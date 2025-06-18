#include <iostream>
#include <thread>

using namespace std;

class X
{
public:
    void do_length_work() {cout<<"do work"<<endl;};
};

void process_big_project(std::unique_ptr<X> x)
{
    x->do_length_work();
    cout<<"ok"<<endl;
}

int main()
{
    X my_x;
    thread t(&X::do_length_work, &my_x); //&my_x 提供 this 指针，确保成员函数在正确的对象上运行
    t.join();

    unique_ptr<X> my_x_ptr(new X);
    my_x_ptr->do_length_work();
    thread tt(process_big_project,std::move(my_x_ptr));
    tt.join();
    //std::thread实例的可移动且不可复制性。不可复制保性证了在同一时间点，
    // 一个std::thread实例只能关联一个执行线程；可移动性使得程序员可以自己决定，哪个实例拥有实际执行线程的所有权。
 
    return 0;
}
