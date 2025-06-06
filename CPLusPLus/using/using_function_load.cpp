#include <iostream>
using namespace std;

class Base
{
public:
   void f(){cout<<"f()"<<endl;}
   void f(int n)//参数不同，函数重载
   {
      cout<<"Base::f(int)"<<endl;
   }

};

class Derived : private Base //私有继承，基类的公有和保护成员都变成派生类的私有成员
{
public:
    using Base::f; // 将Base的f函数引入Derived作用域
    void f(int n) // 覆盖Base的f(int)
    {
        cout<<"Derived::f(int)"<<endl;
    }
};

int main()
{
    Base b;
    Derived d;
    d.f();
    d.f(1);
    return 0;
}
