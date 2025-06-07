#include <iostream>
using namespace std;

struct
{
    int d;
    double b;
} ans;

/**
 * 泛型编程中结合auto，用于追踪函数的返回值类型
 */

template <typename T>
auto multiply(T x,T y)->decltype(x*y) //进行尾置返回类型声明，确保返回类型与 x * y 的类型一致。
{
    return x*y;
}

int main()
{
    int a = 10;
    decltype(a) b = 20; // b是int类型

    decltype(ans) as{1,2.0}; // 定义了一个上面匿名的结构体

    cout << multiply(11, 2) << ":" << as.b << endl;

    return 0;
}