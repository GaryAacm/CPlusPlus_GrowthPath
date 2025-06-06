#include <iostream>

extern int ext;
extern const int ext_extern;

const int *ptr;
int val = 3;

int main()
{
    // 将非const对象的地址赋给const对象的指针:
    ptr = &val;
    std::cout << (ext + 10) << std::endl;
    std::cout << (ext_extern + 10) << std::endl;
    return 0;
}