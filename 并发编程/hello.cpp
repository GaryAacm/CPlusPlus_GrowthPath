#include <iostream>
#include <thread>
#include <unistd.h>

using namespace std;

void hello()
{
    cout<<"hello"<<endl;
}

int main()
{
    thread t(hello);
    t.join(); //wait the thread to finish
    return 0;
}