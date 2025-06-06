#include<iostream>

struct Base
{
    int v1;
private:
    int v2;
public:
    int v3;

    void print()
    {
        printf("%s\n","hello world");
    }

};

int main()
{
    struct Base b;
    Base b2;
    b2.v1=1;
    b2.v3=2;
    b2.print();
    return 0;
}