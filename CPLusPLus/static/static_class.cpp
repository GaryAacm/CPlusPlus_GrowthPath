#include <iostream>
#include <string>
using namespace std;

class Apple
{
public:
    static int i;

    Apple()
    {

    };

    static void printMsg()
    {
        cout<<"Hello world!"<<endl;
    }

    void printMssg()
    {
        cout<<"Hello not static!"<<endl;
    }

};

//需要在类外定义
int Apple::i = 0;


int main()
{
    Apple a;
    Apple b;
    a.i = 2;
    b.i = 3;
    b.printMssg();//只能通过对象调用非静态函数

    a.printMsg();//通过对象调用静态函数

    Apple::printMsg();//通过类名调用静态函数调用静态成员函数
    
    cout << a.i << endl;
    cout << b.i << endl;//输出3，i由成员共享，因为静态变量 i 是由所有类的对象
    return 0;
}
