#include <iostream>
#include<mutex>
#include<thread>
#include<chrono>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

//一个 懒汉式（Lazy Initialization）单例模式，即在第一次调用时才创建实例
class Singleton
{
private:
    Singleton() {}  // 构造函数私有化，防止外部创建对象
    static Singleton *p; // 静态指针，用于保存唯一实例
    static mutex lock_;
public:
    static Singleton *instance(); // // 提供一个对外获取实例的接口
};

// 静态成员初始化（放在类外）懒汉模式
Singleton *Singleton::p = nullptr;
mutex  Singleton::lock_;  // ← 定义 lock_

Singleton* Singleton::instance()
{
    lock_guard<mutex> guard(lock_); //加锁，安全
    if (p == nullptr)
    {
        p = new Singleton(); // 创建实例
    }
    return p;  // 返回实例指针
}
//此处由于创建实例会导致线程竞争，会出现创建多个实例的情况

int main()
{
    Singleton *s1 = Singleton::instance();
    Singleton *s2 = Singleton::instance();
    if (s1 == s2)
    {
        cout << "s1 == s2" << endl;
    }
    else
    {
        cout << "s1 != s2" << endl;
    }
    return 0;
}
