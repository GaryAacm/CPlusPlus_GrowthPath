#include <iostream>
#include <vector>
using namespace std;

#define exp(s) printf("test is %s\n", s)
#define exp1(s) printf("test is %s\n", #s)
#define exp2(s) #s
#define Max(a,b) ((a)>(b) ?(a)\
                  :(b))

#define expA(s) printf("Conncet is :%s\n",Gary_##s) //表示字符串连接


//这里必须定义到连接的字符串，例如上面Gary_s，s要被hello代替，那么就需要定义下面这个
const char * Gary_hello = "I am Gary_hello";

int main()
{
    exp("hello");
    exp1(hello);

    string str = exp2(hello);
    cout << str << " " << str.size() << endl;

    string str1 = exp2(  asdas   bass);

    cout << str1 << " " << str1.size() << endl;

    int max_val = Max(3,6);
    cout<<max_val<<endl;

    expA(hello);

    return 0;
}
