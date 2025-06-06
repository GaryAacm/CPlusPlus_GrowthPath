#include <iostream>
using namespace std;

class MyInt
{
public:
    MyInt(int x) : value(x) {}
    int getValue() const { return value; }

private:
    int value;
};

class MyInt2
{
public:
    explicit MyInt2(int x) : value(x) {}  // 禁止隐式转换
    int getValue() const { return value; }

private:
    int value;
};



void PrintMyInt(const MyInt& mi) //（常量引用）	不拷贝，也不允许修改，只读取对象
{
    cout << mi.getValue() << endl;
}

void PrintMyInt2(const MyInt2& mi) //（常量引用）	不拷贝，也不允许修改，只读取对象
{
    cout << mi.getValue() << endl;
}
int main()
{
    PrintMyInt(42); //函数参数类型不匹配，但存在一个合适的构造函数可以转换。编译器发现查找 MyInt 的构造函数，发现 MyInt(int) 可以匹配
    // PrintMyInt2(24); error 隐式转换不行
    PrintMyInt2(MyInt2(24));
    return 0;
}