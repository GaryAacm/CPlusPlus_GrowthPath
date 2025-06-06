#include <iostream>
#include<bits/stdc++.h>

using namespace std;

/**
 * @brief inline要起作用,inline要与函数定义放在一起,inline是一种“用于实现的关键字,而不是用于声明的关键字”
 *
 * @param x
 * @param y
 *
 * @return 
 */

int Add(int x,int y);
inline int Add(int x,int y)
{
    return x+y;
}

int main()
{
    cout<<Add(1,2)<<endl;
    return 0;
}
