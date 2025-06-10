#include<iostream>
#include<string>
using namespace std;

int main()
{
    string str = string("toptal");
    std::cout << "string object: " << str << " @ " << &str << "\n";

    str += ".com";
    std::cout << "string object: " << str << " @ " << &str << "\n";

    return 0;
}