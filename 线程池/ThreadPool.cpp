#include <iostream>
#include <vector>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <future>

using namespace std;

class ThreadPool
{
public:
    explicit ThreadPool(size_t size) : stop(false)
    {
        for (size_t i = 0; i < size; i++)
        {
            workers.emplace_back([this]
                                 {
                while(true)
                {
                    function<void()> task;

                    {
                        std::unique_lock<mutex> lock(this->queue_mutex);
                        
                        // 等待条件：停止或任务队列非空
                        this->condition.wait(lock,[this]{
                            return this->stop || !this->tasks.empty();
                        });

                        // 如果停止且任务队列为空，结束线程
                        if(this->stop && this->tasks.empty())
                            return;

                        // 从队列取出任务
                        task = move(this->tasks.front());
                        this->tasks.pop();

                    }

                    task();//执行任务
                } });
        }
    }

    // 添加任务到线程池
    template <class F, class... Args>
    auto enqueue(F &&f, Args &&...args)
        -> future<typename result_of<F(Args...)>::type>
    {
        using return_type = typename result_of<F(Args...)>::type;

        // 创建指向任务的智能指针
        auto task = make_shared<packaged_task<return_type()>>(
            bind(forward<F>(f), forward<Args>(args)...));

        // 创建future对象
        future<return_type> res = task->get_future();

        // 将任务添加到任务队列
        {
            std::unique_lock<mutex> lock(queue_mutex);

            if (stop)
            {
                throw runtime_error("enqueue on stopped ThreadPool");
            }

            // 添加任务到队列

            tasks.emplace([task]()
                         { (*task)(); });
        }
        // 通知一个线程等待
        condition.notify_one();

        return res;
    }
    ~ThreadPool()
    {
        {
            unique_lock<mutex> lock(queue_mutex);
            stop = true;
        }

        condition.notify_all();//唤醒全部线程

        for(thread &worker: workers)
        {
            worker.join(); //等待全部线程结束
        }
    }

private:
    vector<thread> workers;             // 工作线程
    queue<std::function<void()>> tasks; // 任务队列

    mutex queue_mutex;
    condition_variable condition;
    bool stop;
};


int main()
{
    ThreadPool pool(4);

    vector<future<int>> results;
    for(int i=0;i<8;i++)
    {
        results.emplace_back(pool.enqueue([i]{
            this_thread::sleep_for(chrono::seconds(1));
            cout<<"Task "<<i<<"complete by Thread"
                <<this_thread::get_id()<<endl;
            return i*i;

        })
       );
    }

    for(auto&& result:results)
    {
        cout<<"Result: "<<result.get()<<endl;
    }
    return 0;
}
