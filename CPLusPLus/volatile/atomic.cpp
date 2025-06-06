#include<iostream>
using namespace std;

#include <atomic>
#include <thread>

std::atomic<int> counter(0);
//int counter = 0;

void countered()
{
    for (int i = 0; i < 1000000; ++i)
        counter++; // 原子操作，线程安全
}

int main()
{
    std::thread t1(countered);
    std::thread t2(countered);

    t1.join();
    t2.join();

    cout << counter << endl;

    return 0;
}
