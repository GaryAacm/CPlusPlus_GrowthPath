#include<iostream>
using namespace std;

#define isGlobal 1

void func()
{
    cout<<"::func"<<endl;
}

namespace ns1 //定义在命名空间里面
{
    void func()
    {
        cout<<"ns1::func"<<endl;
    }
}

namespace ns2
{
#ifdef isNs1
    using ns1::func;// 引入ns1::func
#elif isGlobal
    using ::func;
#else
    void func() // 定义自己的func
    {
        cout<<"other::func"<<endl;
    }
#endif 
}

int main()
{
    ns2::func(); //调用ns2::func()并输出结果,定义了isGlobal，输出::func
    return 0;
}

