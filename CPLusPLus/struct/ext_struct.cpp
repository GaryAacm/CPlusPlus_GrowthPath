#include <iostream>
#include <stdio.h>

struct Base
{
    int v1;

private:
    int v2;

public:
    int v3;

    virtual void print()
    {
        printf("%s\n", "hello world");
    }
};

struct Derived : Base
{
public:
    int v2;

    void print()
    {
        printf("%s\n", "Derived");
    }
};

int main()
{
    Base *b = new Derived();
    b->print();
    return 0; //和类的继承使用方法一样
}
