#include <iostream>
using namespace std;

enum Color
{
    RED,
    COLOR_BLUE
};

enum Feeling {EXCITE,Feeling_BLUE}; //作用域是全局的，不受限,会容易引起命名冲突

int main()
{
    return 0;
}