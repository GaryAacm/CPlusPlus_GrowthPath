#include <iostream>
using namespace std;

class Animal
{
public:
    Animal(int age) //默认构造函数
    {
        cout << "Animal age is called!" << endl;
    }
    Animal(const Animal &) //拷贝构造函数，当需要从现有对象创建新对象时调用
    {
        cout << "Animal(const Animal &) is called!" << endl;
    }
    Animal &operator=(const Animal &) //拷贝赋值运算符
    {
        cout << "Animal &operator=(const Animal &) is called!" << endl;
        return *this;
    }
    ~Animal()
    {
        cout << "~Animal() is called!" << endl;
    }
};

class Dog :public::Animal
{
public:
    Dog(int age) : Animal(age) //通过初始化列表给基类带参构造传递参数
    {
        std::cout << "Dog(int age) is called" << std::endl;
    }
    
    ~Dog()
    {
        cout << "~Dog is called" << endl;
    }

};

int main()
{
    Animal animal(10);//缺少默认参数，必须先构造其基类 Animal
    cout<<endl;
    Dog dog(10);

    //Dog dog()不会调用Dog，因为Dog 类当前没有无参构造函数
    //这不是对象创建，而是被编译器解释为：一个名为 dog 的函数的声明，该函数没有参数
    //返回类型是 Dog
    //任何能被解释为函数声明的东西，都会被解释为函数声明
    //Dog dog(); 完全符合函数声明的语法

    cout<<endl;
    
    return 0;
}