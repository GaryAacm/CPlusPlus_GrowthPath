//g++ global.cpp main.cpp -o extern_example
#include <iostream>

extern int globalCount;
extern const char *appName;
extern void increment();

int main()
{
    std::cout << "Count in main.cpp: " << globalCount << std::endl;
    std::cout << "App name in main.cpp: " << appName << std::endl;

    increment();
    increment();//修改了全局变量globalCount

    return 0;
}