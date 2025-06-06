/**
 * @file default_parameters.cpp
 * @brief 虚函数中默认参数
 * 规则：虚函数是动态绑定的，默认参数是静态绑定的。默认参数的使用需要看指针或者应用本身的类型，而不是对象的类型！
 * @author Gary
 * @version v1
 * @date 2025-06-05
 */

#include <iostream>
using namespace std;

class Base
{
public:
    virtual void fun(int x = 10) { cout << "Base::fun(), x = " << x << endl; }
};

class Deived : public Base
{
    public:
    virtual void fun(int x=20) // 重写基类的虚函数，并修改默认参数为 20
    {
        cout << "Deived::fun(), x = " << x << endl;
    }
};

int main()
{
    Deived d1;
    Base *p = &d1;
    p->fun();// Deived::fun(), x = 10
    return 0;
}

/*
关键规则
虚函数是动态绑定的：
调用 p->fun() 时，由于 fun() 是虚函数，
实际执行的是 Deived::fun()（因为 p 指向的是 Deived 对象）。

默认参数是静态绑定的：
默认参数的值是在 编译时 根据 指针或引用的类型（Base*） 决定的，
而不是运行时的对象类型（Deived）。
因此，p->fun() 使用的是 Base::fun(int x = 10) 的默认参数 10，
而不是 Deived::fun(int x = 20) 的 20
*/
