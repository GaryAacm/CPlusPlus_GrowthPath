/*
编译：gcc -c add.c 
g++ extern.cpp add.o -o extern
*/

#include<iostream>
extern "C"
{
    #include "add.h"
}
using namespace std;

int main()
{
    add(1,2);
    return 0;
}
