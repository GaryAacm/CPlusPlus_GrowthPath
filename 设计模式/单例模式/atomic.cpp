#include <iostream>
#include<mutex>
#include<unistd.h>
#include<atomic>
using namespace std;

class Singleton
{
private:
    Singleton() {}  // 构造函数私有化，防止外部创建对象
    static atomic<Singleton *> p; // 静态指针，用于保存唯一实例
    static mutex lock_;
public:
    static Singleton *instance(); // 提供一个对外获取实例的接口

    // 实现一个内嵌垃圾回收类
    class CGarbo
    {
        public:
        ~CGarbo()
        {
            if(Singleton::p)
            {
                delete Singleton::p;
            }
        }
    };
    static CGarbo garbo;// 定义一个静态成员变量，程序结束时，系统会自动调用它的析构函数从而释放单例对象
};


mutex Singleton::lock_;
atomic<Singleton*> Singleton::p{nullptr}; //保证读写操作的原子性
Singleton::CGarbo Singleton::garbo;

Singleton *Singleton::instance()
{
    Singleton *tmp = p.load(memory_order_relaxed); //(1) 第一次无锁读取
    atomic_thread_fence(memory_order_acquire); //(2) 内存屏障
    if(tmp==nullptr)
    {
        lock_guard<mutex> guard(lock_);
        tmp = p.load(memory_order_relaxed); //(3) 再次读取
        if(tmp==nullptr)
        {
            tmp = new Singleton();
            atomic_thread_fence(memory_order_release); //(4) 内存屏障
            p.store(tmp, memory_order_relaxed); //(5) 写入
        }
    }
    return p;
}


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
