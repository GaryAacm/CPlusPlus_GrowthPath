#include <iostream>
using namespace std;

// 虚函数与多态
class Employee
{
public:
    virtual void raiseSalary()
    {
        cout << "Raise Salary" << endl;
    }

    virtual void promote()
    {
        cout << "Get Promote" << endl;
    }
};

class Enginneer : public Employee
{
public:
    virtual void raiseSalary()
    {
        cout << "Raise Enginneer Salary" << endl;
    }
    virtual void promote()
    {
        cout << "promo Enginneer" << endl;
    }
};

class Manager : public Employee
{
    virtual void raiseSalary() { cout << "Raise Manager Salary" << endl; }

    virtual void promote()
    {
        cout<<"promote Manager"<<endl;
    }
};

void globalRaiseSalary(Employee *emp[], int n)
{
    for (int i = 0; i < n; i++)
    {
        emp[i]->raiseSalary();
    }
}

int main()
{
    Employee *emp[] = { new Manager(), new Enginneer() };//存储派生类对象
    globalRaiseSalary(emp,2);

    return 0;
}
