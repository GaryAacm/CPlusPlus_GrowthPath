#include <iostream>
#include <string>
using namespace std;

class Animal
{
public:
    Animal(int age,string name):age_(age),name_(name) //默认构造函数
    {
        cout << "Animal age is called!" << endl;
    }
    Animal(const Animal &other):age_(other.age_),name_(other.name_) //拷贝构造函数，当需要从现有对象创建新对象时调用
    {
        cout << "Animal(const Animal &) is called!" << endl;
    }
    Animal &operator=(const Animal &other) //拷贝赋值运算符
    {
        if(this!=&other)
        {
            age_ = other.age_;
             // name_ 是 const 类型，无法赋值，只能在初始化列表中赋值
        }
        cout << "Animal &operator=(const Animal &) is called!" << endl;
        return *this;
    }
    ~Animal()
    {
        cout << "~Animal() is called!" << endl;
    }
private:
    int &age_;
    const string name_;//const数据成员、引用数据成员必须用初始化列表初始化，而不能通过赋值初始化
};

class Dog :public::Animal
{
public:
    Dog(int age) : Animal(age,"Xiaodaji") //通过初始化列表给基类带参构造传递参数
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
    Animal animal(10,"Xiaodaji");//缺少默认参数，必须先构造其基类 Animal
    cout<<endl;
    Dog dog(5);
    cout<<endl;
    
    return 0;
}