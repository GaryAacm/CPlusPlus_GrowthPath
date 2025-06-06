#include <iostream>
using namespace std;

struct A
{
    A(int) {}                              // 这个构造函数接受一个 int 参数，可以用来从 int 构造 A 类型的对象。
    operator bool() const { return true; } // 这个函数允许 A 类型的对象隐式转换为 bool
};

struct B
{
    explicit B(int) {}
    explicit operator bool() const { return true; }
};

void doA(A a) {}

void doB(B b) {}

int main()
{
    A a1(1);
    A a2 = 1;    // ok
    A a3{1};     // OK：直接列表初始化
    A a4 = {1};  // OK：直接复制列表初始化
    A a5 = A(1); // OK：允许 static_cast 的显式转换

    doA(1); // OK：允许从 int 到 A 的隐式转换

    bool a6(a1);                     // OK：使用转换函数 A::operator bool() 的从 A 到 bool 的隐式转换
    bool a7 = a1;                    // OK：使用转换函数 A::operator bool() 的从 A 到 bool 的隐式转换
    bool a8 = static_cast<bool>(a1); // OK ：static_cast 进行直接初始化

    B b1(1);
    //B b2 = 1; // error：不允许从 int 到 B 的隐式转换
    B b3{1};  // OK：直接列表初始化
    //B b4 = {1}; // error：
    B b5 = B(1); // OK：允许 static_cast 的显式转换

    // doB(1); // error：不允许从 int 到 B 的隐式转换

    bool b6(b1);              
    //bool b7 = b1;      // error：不允许从 B 到 bool 的隐式转换
    bool b8 = static_cast<bool>(b1); // OK ：static_cast 进行直接初始化

    return 0;
}

