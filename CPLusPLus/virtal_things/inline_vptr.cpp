#include <iostream>
using namespace std;

class Base
{
public:
    inline virtual void fun()
    {
        cout << "Base::fun()" << endl;
    }
};

class Derived : public Base
{
public:
    inline void fun()
    {
        cout << "Derived::fun()" << endl;
    }
};

int main()
{
    // fun()，是通过类（Base）的具体对象（b）来调用的，编译期间就能确定了，所以它可以是内联的，但最终是否内联取决于编译器。
    Base b;
    b.fun();

    // 此处的虚函数是通过指针调用的，呈现多态性，需要在运行时期间才能确定，所以不能为内联。
    Base *ptr = new Derived ();
    ptr->fun();

    Derived d;
    d.fun(); //直接调用会内联

    delete ptr;

}
