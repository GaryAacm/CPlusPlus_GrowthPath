#include <iostream>
#include <thread>

using namespace std;

//线程标识符，区分主线程和其他工作线程，并根据不同的线程执行不同的操作
thread::id master_thread ; //全局声明


void do_master_thread_work()
{
    cout << "master" << endl;
}

void do_common_work()
{
    cout << "common" << endl;
}

void some_core_part_of_algorithm()
{
    if(this_thread::get_id() == master_thread)
    {
        do_master_thread_work();
    }
    else do_common_work();
}

int main()
{
    master_thread = this_thread::get_id();//初始化主线程，获取ID
    std::cout << "master_thread: " << master_thread << endl;
    cout << "master_thread run is:" << endl;
    some_core_part_of_algorithm();

    cout << "thread run is:" << endl;
    thread t(some_core_part_of_algorithm);
    t.join();

    return 0;

}
