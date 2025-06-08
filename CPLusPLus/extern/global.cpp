#include <iostream>

// 定义全局变量（分配内存）
int globalCount = 0;          // 可修改的全局变量
const char *appName = "Demo"; // 全局常量字符串

void increment()
{
    globalCount++;
    std::cout << "Count in globals.cpp: " << globalCount << std::endl;
}