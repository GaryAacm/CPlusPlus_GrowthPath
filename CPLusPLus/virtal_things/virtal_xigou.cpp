#include <iostream>
using namespace std;

class base
{
public:
    base() { cout << "Constructing base \n"; }
    virtual ~base() { cout << "Destructing base \n"; }
};

class derived : public base
{
public:
    derived() { cout << "Constructing derived \n"; }
    ~derived() { cout << "Destructing derived \n"; }

};


// deived 继承了base，因此在构造的时候先构造base的构造，在析构完自己的析构之后会调用base的析构
int main()
{
    derived *d = new derived;
    base *b = d;

    delete d; //b与d都被删除

    return 0;
}

