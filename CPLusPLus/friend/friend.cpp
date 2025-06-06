#include <iostream>
using namespace std;

class A
{
public:
    A(int aa):a(aa){};
    friend void print(A &a); //友元函数
private:
    int a;
};

void print(A &aa)
{
    cout << aa.a << endl;
}

int main()
{
    A a(3);
    print(a);
    return 0;
}
