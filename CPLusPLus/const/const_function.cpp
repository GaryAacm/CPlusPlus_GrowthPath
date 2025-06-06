#include <iostream>
using namespace std;

const int func1();

void func(const int var); // 传递过来的参数不可变
void func(int *const var); // 指针本身不可变

//给src加上const修饰后，如果函数体内的语句试图改动src的内容，编译器将指出错误
void StringCopy(char *dst, const char *src); 

void func(const A &a); // 传递过来的对象不可变,借用引用改别名，不需要临时生产对象，提高效率
//不用引用，需要生产临时对象，临时对象的构造、复制、析构过程都将消耗时间。


