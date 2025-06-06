#include <iostream>
#include <typeinfo>

using namespace std;

class B
{
    virtual void fun() {}
};
class D : public B
{
};

int main()
{
    B *b = new D;
    B &obj = *b;
    D *d = dynamic_cast<D *>(b);

    if (d != NULL)
        cout << "works" << endl;
    else
        cout << "cannot cast B* to D*";

    try
    {
        D &dobj = dynamic_cast<D &>(obj);
        cout << "works" << endl;
    }
    catch(bad_cast bc)
    {
        cout << bc.what() << endl;
    }
    
    return 0;
}