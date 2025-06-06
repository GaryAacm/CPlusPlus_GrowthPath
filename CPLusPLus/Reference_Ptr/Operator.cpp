#include <iostream>
using namespace std;

struct Point
{
    int x, y;
    Point operator+(const Point &temp) //利用引用传入
    {
        Point result;
        result.x = x + temp.x;
        result.y = y + temp.y;
        return result;
    }
};

int main()
{
    Point p1{1, 2};
    Point p2{3, 4};
    Point p3 = p1 + p2;
    cout << p3.x << " " << p3.y << endl;
    return 0;
}