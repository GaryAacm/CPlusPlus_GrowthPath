#include <iostream>
using namespace std;

class Base
{
private:
    virtual void fun()
    {
        cout << "Base::fun()" << endl;
    }
    friend int main(); //main作为友元才能访问私有类，相当于一个接口
};

class Derived:public Base
{
    public:
    void fun()
    {
        cout << "Derived::fun()" << endl;
    }

};

int main()
{
    Derived d;
    d.fun();
    Base *p = &d;
    //上面等价于Base *p = new Derived();
    p->fun();
    return 0;
}
