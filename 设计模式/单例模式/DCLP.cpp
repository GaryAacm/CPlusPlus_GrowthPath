#include <iostream>
#include<mutex>
#include<unistd.h>
using namespace std;

class Singleton
{
private:
    Singleton() {}  // 构造函数私有化，防止外部创建对象
    static Singleton *p; // 静态指针，用于保存唯一实例
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

// 静态成员初始化（放在类外）懒汉模式
Singleton *Singleton::p = nullptr;
mutex Singleton::lock_;


Singleton*  Singleton::instance()
{
    if (p == nullptr)
    {
        lock_guard<mutex> guard(lock_);
        if(p == nullptr)
        {
            Singleton *tmp = static_cast<Singleton *>(operator new(sizeof(Singleton)));
            new(p)Singleton();
            p = tmp;
        }//operator new+placement new
        
        //p = new Singleton(); // 双重加锁检查
    }
    return p;  // 返回实例指针
}

//C++11之后，线程安全
// singleton *singleton::instance() {
//     static singleton p;
//     return &p;
// }


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
