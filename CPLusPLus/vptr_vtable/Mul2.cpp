/**
 * @file Mul.cpp
 * @brief C++多态(进阶版)
 * 编译：g++ -o Mul2 Mul2.cpp
 * @author 小子
 * @version v1
 * @date 2025-06-03
 */

#include <iostream>
using namespace std;

class Animal
{
public:
    virtual void speak()
    {
        cout << "This is an animal!" << endl;
    }
};

// 派生类dog,继承实现多态
class Dog : public Animal
{
public:
    virtual void speak()
    {
        cout<<"This is a dog!"<<endl;
    }

};

class Cat:public Animal
{
    public:
    virtual void speak()
    {
        cout<<"This is a cat!"<<endl;
    }

};

int main()
{
    Animal animal;
    Dog dog;
    Cat cat;

    animal.speak();
    dog.speak();
    cat.speak();

    // 多态
    Animal *pAnimal = &animal;
    pAnimal->speak();

    pAnimal = &dog;
    pAnimal->speak();

    pAnimal = &cat;
    pAnimal->speak();

    //创建指针来实现多态
    Dog *pdog = new Dog();
    Cat *pcat = new Cat();

    pdog->speak();
    pcat->speak();

    pAnimal = pdog;
    pAnimal->speak();

    pAnimal = pcat;
    pAnimal->speak();


    delete pdog;
    delete pcat;

    return 0;
    
}
