#include <iostream>
#include <thread>
#include <unistd.h>
#include <vector>
#include <algorithm>
#include <functional>
#include <mutex>

using namespace std;

void fun(int x)
{
    while (x-- > 0)
    {
        cout << "fun ptr " << x << endl;
    }
}

class Base
{
public:
    void operator()(int x)
    {
        while (x-- > 0)
        {
            cout << "Base " << x << endl;
        }
    }
};

class Base2
{
public:
    void fun(int x)
    {
        while (x-- > 0)
        {
            cout << "Base2 " << x << endl;
        }
    }
};

class Base3
{
public:
    static void fun(int x)
    {
        while (x-- > 0)
        {
            cout << "Base3 " << x << endl;
        }
    }
};

void run(int count)
{
    while(count-->0)
    {
        cout<<"run "<<count<<endl;
    }
}

int main()
{
    thread t1(fun, 10); // 函数指针创建线程
    t1.join();

    // lambda函数
    thread t2([](int x)
              {
        while(x-->0)
        {
            cout<<"lambda "<<x<<endl;
        } }, 11); // 传递参数11
    t2.join();

    // 仿函数
    thread t3(Base(), 12);
    t3.join();

    // 非静态成员函数,通过对象调用
    Base2 b;
    thread t4(&Base2::fun, &b, 10);
    t4.join();

    // 静态,静态成员函数属于类本身，而不是类的对象,不需要对象来调用
    // 没有 this 指针，不能访问非静态成员变量或方法
    thread t5(Base3::fun, 10);
    if (t5.joinable())
        t5.join();
    
    thread t6(run,10);
    cout << "main()" << endl;
    t6.detach();//主线程不会等待t6执行完
    if(t6.joinable())
        t6.detach();
    return 0;
}