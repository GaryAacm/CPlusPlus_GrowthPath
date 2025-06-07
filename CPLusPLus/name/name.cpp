#include <iostream>
using namespace std;

int count = 0;

class A
{
public:
    static int count; // 类A的count (A::count)
};

int A::count = 0;
int main()
{
    ::count = 1;
    ::count = 1;  // 设置全局的count为1
    A::count = 5; // 设置类A的count为2
    cout << A::count << endl;
}
