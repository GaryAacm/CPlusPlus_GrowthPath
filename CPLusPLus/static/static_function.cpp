#include <iostream> 
#include <string> 



void demo()
{
    static int count =0;
    std::cout << "count = " << count << std::endl;
    count++;
}

//count 在每次调用都不会改变，因为是静态变量，只在第一次调用时初始化，之后的调用都不会再次初始化。
int main()
{
    for(int i=0;i<5;i++)
    {
        demo();
    }
    return 0;
    
}
