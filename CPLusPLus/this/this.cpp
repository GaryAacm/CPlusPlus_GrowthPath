#include <iostream>
#include <cstring>
using namespace std;

class Person
{
public:
    typedef enum
    {
        BOY = 0,
        GIRL
    } SexType;
    Person(char *n, int a, SexType s)
    {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
        age = a;
        sex = s;
    }
    int get_age() const
    {
        return this->age;
    }
    Person &add_age(int a)
    {
        this->age += a;
        return *this; // 返回当前对象本身的引用，return this返回的是当前对象地址
    }

    // static void test()
    // {
    //     this->age = 10; // ❌ 错误：static 函数中没有 this 指针
    // }
    ~Person()
    {
        delete[] name;
    }

private:
    char *name;
    int age;
    SexType sex;
};

int main()
{
    Person p("Gary", 18, Person::BOY);
    cout << p.get_age() << endl;
    cout << p.add_age(10).get_age() << endl;

    return 0;
}
