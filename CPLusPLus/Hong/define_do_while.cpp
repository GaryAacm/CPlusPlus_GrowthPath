#include <iostream>
using namespace std;

#define EMPTYMICRO do{}while(0)

#define f1() cout << "f1()" << endl;
#define f2() cout << "f2()" << endl;

#define run(){f1();f2();}

#define fun1() do{f1();f2();}while(0)

int main()
{
    
}
