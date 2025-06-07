#include <iostream>
using namespace std;

// 为了避免命名冲突，可以用 namespace 封装枚举
namespace Color
{
    enum Type
    {
        RED = 15,
        YELLOW,
        BLUE
    };
};

// 命名空间可以被后续代码扩展，封闭性不够强。
// 如果多个开发者定义相同的 namespace Color，仍然可能冲突。

// 使用 struct 或 class 封装枚举
// 语法稍显冗长
struct Color1
{
    enum Type
    {
        RED = 102,
        YELLOW,
        BLUE
    };
};

// C++11 引入 enum class（强类型枚举）

enum class Color2
{
    RED = 114514,
    YELLOW,
    BLUE
}; // 默认int
enum class Color3 : char
{
    RED = 'r',
    BLUE
}; // char类型

int main()
{
    Color::Type c = Color::RED;
    cout << c << endl;

    Color1 c1 ;
    cout<<c1.RED<<endl;

    Color1::Type c11 =  Color1::BLUE; //104,枚举
    cout<<c11<<endl;

    Color2 c2 = Color2::RED;
    cout<<static_cast<int>(c2)<<endl; //需要显式转换

    char c3 = static_cast<char>(Color3::RED);
    cout<<c3<<endl;


    return 0;
}
