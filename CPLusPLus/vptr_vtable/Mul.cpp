/**
 * @file Mul.cpp
 * @brief C++多态
 * 编译：g++ -o Mul Mul.cpp
 * @author 小子
 * @version v1
 * @date 2025-06-03
 */

#include<iostream>
using namespace std;

class A
{
public:
    virtual void f()
    {
        cout << "A" << endl;
    }

};

class B : public A
{
public:
    virtual void f()
    {
        cout << "B" << endl;
    }

};

int main()
{
    A a;
    B b;
    A *pa = &a; //父指针指向父类对象
    pa->f();

    pa = &b; //父指针指向子类对象
    pa->f();//调用派生类同名函数

    return 0;
}