#include <iostream>
using namespace std;

struct A
{
    int v1, v2;
};

class MyClass
{
public:
    MyClass()
    {
        cout << "MyClass constructed" << endl;
    }
    ~MyClass()
    {
        cout << "MyClass destructed" << endl;
    }
    void show()
    {
        cout << "MyClass show method" << endl;
    }
};

union Dataed
{
    int i;
    float f;
    char str[20];
    struct A a;
};

int main()
{
    Dataed d;

    d.i = 10;
    cout<<d.i<<endl;
    d.a.v1=100;
    cout<<d.a.v1<<endl;
    return 0;
}


