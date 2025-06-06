#define NDEBUG // 加上这一行可以忽略断言，可以运行到输出no assert
#include <iostream>
#include <assert.h>

using namespace std;

int main()
{
    int x = 7;

    x = 9;
    assert(x == 7);

    cout << "no assert" << endl;

    return 0;
}
