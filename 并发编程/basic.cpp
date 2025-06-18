#include <iostream>
#include <thread>
#include <unistd.h>
#include <cassert>

using namespace std;

class background_task
{
public:
    void operator()() const
    {
        cout << "ok" << endl;
    } // 函数调用运算符,它使得该类的对象可以像函数一样被调用
};

void do_something(int &i)
{
    cout << "do_something" << endl;
}

struct func
{
    int &i;
    func(int &i_) : i(i_) {}

    void operator()()
    {
        for (unsigned j = 0; j < 100000; j++)
        {
            do_something(i);
        }
    }
};

void f()
{
    int some_local_state = 0;
    func my_func(some_local_state);
    thread t(my_func);
    t.join();
}

//RAII（Resource Acquisition Is Initialization）包装类
class thread_guard
{
    thread &t;

public:
    explicit thread_guard(thread &t_) : t(t_) {}
    ~thread_guard()
    {
        if(t.joinable())
        {
            t.join();
        }
    }
    thread_guard(thread_guard const&) = delete;
    thread_guard &operator=(thread_guard const&) = delete;
    //删除的拷贝操作
    //因为类持有线程引用，拷贝可能导致多个 thread_guard 管理同一个线程
    
};

void f1()
{
    int some_local_state=0;
    func my_func(some_local_state);
    thread t(my_func);
    thread_guard g(t);
    
}
// 当线程执行到此处时，局部对象就要被逆序销毁了。因此，thread_guard对象g是第一个被销毁的，
// 这时线程在析构函数中被加入2到原始线程中。

int main()
{
    background_task f;
    thread t(f);
    t.join(); //ok

    //加括号强制解释为临时对象创建，而不是函数声明
    thread my_thread1{background_task()};
    // my_thread1((background_task())); //解决 "Most Vexing Parse" 问题
    my_thread1.join();

    //后台运行线程
    thread  my_thread2(f);
    t.detach();   // 将线程分离
    assert(!t.joinable());  // 验证线程已不可加入

    return 0;
}
