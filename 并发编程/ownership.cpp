#include <iostream>
#include <thread>
#include <unistd.h>
#include <vector>
#include <algorithm>
#include <functional>
#include <mutex>

using namespace std;

void some_function() { cout << "some_function" << endl; }

void some_other_function() { cout << "other_function" << endl; }

void do_something(int i)
{
    cout << i << endl;
}

struct func
{
    int &i;

    func(int &i_) : i(i_) {}

    void operator()()
    {
        for (unsigned j = 0; j < 1000000; ++j)
        {
            do_something(i);
        }
    }
};

class scoped_thread
{
    thread t;

public:
    explicit scoped_thread(thread t_) : t(move(t_))
    {
        if (!t.joinable())
        {
            throw logic_error("No thread");
        }
    }

    ~scoped_thread()
    {
        t.join();
    }

    scoped_thread(scoped_thread const &) = delete;

    scoped_thread &operator=(scoped_thread const &) = delete;
};

mutex m;

void do_work(unsigned id)
{
    lock_guard<mutex> lock(m);
    cout << "thread id: " << id << endl;
}

void f()
{
    vector<thread> threads;           // 1. 创建线程容器
    for (unsigned i = 0; i < 20; i++) // 2. 创建20个线程
    {
        threads.push_back(thread(do_work, i)); // 3. 创建线程并放入容器
    }
    for_each(threads.begin(), threads.end(), // 4. 等待所有线程完成
             mem_fn(&thread::join));
}

int main()
{
    // thread t1(some_function);
    // thread t2 = move(t1); // 此时t1是空的线程,不能t1.join()
    //t2.join();

    thread t1 = thread(some_other_function);
    thread t2 = thread(some_function);
    thread t3;
    t3 = move(t2); //t2空的，不能t2.join()

    t1.join();
    t3.join();

    f(); 

    // scoped_thread t4(thread(some_function()));

    return 0;
}