#include<iostream>
using namespace std;

struct _PRCODE
{
    unsigned int code1:2;
    unsigned int code2:2;
    unsigned int code3:8; //prcode.code3 为 8 Bits 的位域成员，其容量为 2^8 = 256，即赋值范围应为 [0,255]
};
struct _PRCODE prcode;

union  u_box
{
    struct _PRCODE prcode2;
    unsigned int ui_box;
    
};//共享一块内存


int main()
{
    prcode.code1 = 1;
    prcode.code2 = 2;
    prcode.code3 = 100;
    cout<<sizeof(prcode)<<endl;
    
    //所有成员可以完全放入一个 unsigned int（32 bits）中，因此 sizeof(prcode) 的结果是 4 字节（32 bits）
    union u_box ubox;
    ubox.ui_box=0;
    ubox.prcode2.code1=1;
    cout<<sizeof(u_box)<<endl;
    
}
