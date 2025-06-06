#include <iostream>
using namespace std;

const char *p_string = "hello"; // 指向常量的指针，指针所指向的内容不能被修改，但指针本身可以指向其他地址。

const int p = 10;
const void *vp = &p;
// void *vp = &p; //error

// char * const q = "hello_world"; // 常指针，const指针必须进行初始化，且const指针不能修改。

void f(const int i)
{
    // i++; 错误，不可以修改
}
int main()
{
    const int a = 100; // 定义常量

    int num = 10;
    int num_1 = 100;

    //这意味着ptr 本身的值（即它存储的地址）不能被改变
    int * const ptr = &num;

    cout << *ptr << endl;

    *ptr = 20; //修改 ptr 所指向的值

    //不能修改 ptr 的值，但可以修改 *ptr，常指针本身不可以改变
    //ptr = &num_1; //  error: assignment of read-only variable 'ptr'

    cout<<*ptr<<endl;

    int *t = &num;
    *t = 1;
    cout << *ptr << endl;

    //指向常量的常指针
    const int p_1 =3;
    const int * const ptr_2 = &p_1;

    return 0;
}