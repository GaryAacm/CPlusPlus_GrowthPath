#include <iostream>
#include <vector>
#include "dbg.h"
using namespace std;

//输出中通过 dbg 宏打印了变量的值和类型，帮助你跟踪程序的执行流程和中间结果。
int factorial(int n)
{
    if (dbg(n <= 1))
    {
        return dbg(1);
    }
    else
    {
        return dbg(n * factorial(n - 1));
    }
}

int main()
{
    string message = "hello";
    dbg(message);

    const int a = 5;
    const int b = dbg(3 * a) + 1;

    vector<int> numbers{b,13,42};
    dbg(numbers);

    dbg(factorial(5));

    return 0;
}
