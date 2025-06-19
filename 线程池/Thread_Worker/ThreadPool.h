#include <vector>
#include <thread>
#include <mutex>
#include <atomic>
#include <condition_variable>

enum ThreadState
{
    THREAD_CREATE = 1,
    THREAD_RUNNING,
    THREAD_END
};

// 线程接口
class IWorker
{
public:
    virtual ~IWorker() = default;
    virtual void doJob() = 0;
    virtual int getProcessCount() = 0;
};

class Thread
{
public:
    explicit Thread(IWorker *worker);
    ~Thread();

    void startThread();
    ThreadState getState() const; // 获取线程状态
    int getProcessCount() const;

private:
    void run(); // 线程执行函数
private:
    std::atomic<ThreadState> m_state; // 线程状态
    std::thread m_thread;             // 线程对象
    IWorker *m_worker;                // 工作接口指针
};

// 线程池
class ThreadPool
{
public:
    ThreadPool();
    ~ThreadPool();

    void addJob(IWorker *worker); // 添加任务
    size_t getThreadNum() const;
    bool isAllFinish() const;
    int  getProcessCount() const;
private:
    std::vector<Thread*> m_threads;
    mutable std::mutex m_mutex; //互斥锁
};

