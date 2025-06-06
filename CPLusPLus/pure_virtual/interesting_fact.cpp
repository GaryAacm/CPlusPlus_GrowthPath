#include <iostream>
using namespace std;

class Base
{
public:
    virtual void fun() = 0;
    int x;
    Base(int i){x=i;}
};


class Derived : public Base
{
int y;
public:
    //利用参数 i 调用了基类构造函数 Base(i)，赋值并初始化了基类成员 x；
    //然后通过 y = j;，初始化了派生类自己的成员 y。
    
    Derived(int i,int j) : Base(i){y=j;} //继承Base里面的初始化
    void fun()
    {
        cout<<"x="<<x<<endl;
        cout<<"y="<<y<<endl;
    }
     
};

int main()
{
    Derived d(1,2);
    d.fun();
    return 0;
}
