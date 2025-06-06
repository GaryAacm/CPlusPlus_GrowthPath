#include<iostream>
using namespace std;

int main()
{
    const volatile int local = 10; //告诉编译器不要优化对该变量的访问，每次都必须从内存读取/写入（防止缓存或优化掉看似冗余的操作）。
    int *ptr = (int *)&local; //(int *) 强制转换为普通 int*，去掉了 const 和 volatile 属性

    printf("Initial value of local : %d \n", local);

    *ptr = 100; //现在 ptr 是一个普通指针，可以用于修改 local 的值（

    printf("After changing value of local : %d \n", local);

    return 0;
}
