/**
 * @file pure_virtual.cpp
 * @brief 纯虚函数：没有函数体的虚函数
 * 抽象类：包含纯虚函数的类
 *
 * @author Gary
 * @version v1
 * @date 2025-06-04
 */

#include <iostream>
using namespace std;

class Base
{
private:
    int a;

public:
    virtual void show() = 0; // 纯虚函数，等待后面继承重写实现
    int getA() { return a; }
};

class Derived : public Base
{
    public:
    void show() //继承重新实现纯虚函数
    {
        cout<<"In Derived show()"<<endl;
    }
    Derived(){};

};

int main()
{
    /*
     * 1. 抽象类只能作为基类来派生新类使用
     * 2. 抽象类的指针和引用->由抽象类派生出来的类的对象！
     */
    
    // Base a; // error 抽象类，不能创建对象

    Base *a1; //ok 可以创建抽象类的指针

    // Base *a2 = new A(); // error 不能创建抽象类的对象

    Base *p = new Derived(); // ok 可以创建抽象类的派生类的对象

    p->show();

    return 0;
}
