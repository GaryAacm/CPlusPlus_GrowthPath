#include <iostream>
using namespace std;

class A
{
};

class A1
{
public:
    char a;//对齐4B
    int b;
};

class A2 : A1
{
public:
    short a;
    long b;
};

class A3
{
    virtual void fun(){};
};
class C1:public A3
{
};

class B
{
public:
    char b;
    void function() {};
    virtual void f() {};
    static int a;
    static int c;
};

class C
{
    virtual void fun() {};
    virtual void fun1() {};
    virtual void fun2() {};
    virtual void fun3() {};
};

int main()
{
    cout << sizeof(A) << endl; // 空类大小1字节
    cout << sizeof(B) << endl; // 16字节,vptr指针=8,vptr 的存在让类的对齐要求是 8 字节,所以char对齐要8B
    cout << sizeof(C) << endl; // 8字节,多个vptr指针=8

    cout << sizeof(A1) << endl;
    cout << sizeof(A2) << endl;
    cout<<sizeof(C1)<<endl;// 8字节,继承虚函数
    return 0;
}