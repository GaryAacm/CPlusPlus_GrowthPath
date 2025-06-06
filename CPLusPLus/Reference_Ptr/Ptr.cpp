/**
 * @file Ptr.cpp
 * @brief C++引用与指针
 * 编译：g++ -o Ptr Ptr.cpp
 * @author 小子
 * @version v1
 * @date 2025-06-04
 */

#include <iostream>
#include<vector>
using namespace std;

void test_p(int *p)
{
    if (p != nullptr)
        *p = 3;
    return;
}

void test_r(int &r)
{
    r = 3; // 由于引用不能为空，所以此处无需判断r的有效性就可以对r直接赋值
    return;
}

void test(const vector<int> &v) //v只允许读
{
    for(int i:v)
    {
        cout<<i<<' ';
    }
    cout<<endl;
}

int main()
{
    // 指针可以随时改变指向，但是引用只能指向初始化时指向的对象，无法改变。
    int a=1,b=2;
    int *p = &a;

    cout<<"p is "<<*p<<endl;
    p = &b;
    cout<<"p is "<<*p<<endl;

    int &r = a;
    cout<<"r is "<<r<<endl;

    r = b;
    cout<<"r is "<<r<<endl;
    cout<<"a is "<<a<<endl;//引用r依然指向a，但a的值变成了b

    vector<int> v = {1,2,3,4,5};
    test(v);

    return 0;

}
