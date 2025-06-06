/**
 * @file vptr1.cpp
 * @brief C++虚函数vptr和vtable
 * 编译：g++ -o vptr vptr1.cpp
 * @author 小子
 * @version v1
 * @date 2025-06-03
 */

#include <iostream>
using namespace std;

//函数指针
typedef void (*Fun)();

// 基类
class Base
{
public:
    Base() {};
    virtual void func1()
    {
        cout << "Base func1()" << endl;
    }

    virtual void func2()
    {
        cout << "Base func2()" << endl;
    }
    ~Base() {};
};

// 派生类
class Derived : public Base
{
public:
    Derived() {};
    void func1()
    {
        cout << "Derived func1()" << endl;
    }

    void func2()
    {
        cout << "DerivedClass func2()" << endl;
    }
    ~Derived() {};
};

//获取vptr和func的地址，vptr指向的是一块内存，这块内存存放的是虚函数地址，这块内存就是我们所说的虚表
//通过vptr指针访问virtual table，因为虚表中每个元素(虚函数指针)在64位编译器下是8个字节，因此通过*(unsigned long *)vptr_addr取出前8字节，* 后面加上偏移量就是每个函数的地址！
Fun getAddr(void * obj,unsigned int offset)
{
    cout<<"======================="<<endl;
    void* vptr_addr = (void *)*(unsigned long *)obj;//获取vptr的地址
    printf("vptr_addr:%p\n",vptr_addr);
    void* func_addr =  (void*)*((unsigned long *)vptr_addr+offset);//获取func的地址
    printf("func_addr:%p\n",func_addr);
    return (Fun)func_addr;
}

int main(void)
{
    Base ptr;
    Derived d;
    Base *pt = new Derived();
    Base &pp = ptr;
    Base &p = d;

    ptr.func1();

    pp.func1();

    pt->func1();

    p.func1();

    // 手动查找vptr 和 vtable
    Fun f1 = getAddr(pt, 0);
    f1();

    Fun f2 = getAddr(pt, 2);
    f2();

    delete pt;
    return 0;
}