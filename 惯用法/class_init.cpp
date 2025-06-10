#include <iostream>
using namespace std;

class Animal
{
public:
    Animal() //默认构造函数
    {
        cout << "Animal is called!" << endl;
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

class Dog
{
public:
    Dog(const Animal &animal) : __animal(animal)
    {
        std::cout << "Dog(const Animal &animal) is called" << std::endl;
    }
    
    ~Dog()
    {
        cout << "~Dog is called" << endl;
    }

private:
    Animal __animal;
};

int main()
{
    Animal animal;
    cout<<endl;
    Dog dog(animal);//当需要从现有对象创建新对象时调用
    cout<<endl;
    
    Animal a1,a2;//调用拷贝赋值运算符
    a1=a2;
    cout<<endl;
    Animal a3;
    a3=a1;
    cout<<endl;
    return 0;
}