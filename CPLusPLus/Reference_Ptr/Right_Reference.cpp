#include <iostream>
#include <vector>
using namespace std;

void processVector(vector<int> &&v) //右值引用作函数参数
{
    for (int num : v)
    {
        cout << num << ' ';
    }
    cout << endl;

    vector<int> movedVec = std::move(v); // 资源已经转移

    for (int num : v)
    {
        cout << num << ' ';
    }
    cout << endl;
}

int main()
{
    vector<int> vv = {1, 2, 3, 4, 5};
    processVector(move(vv)); // move实现右值引用

    cout << "Original vector after move: ";

    for (int num : vv)
    {
        cout << num << ' ';
    }
    cout << endl;

    vector<int> myVec{1, 2, 3, 4, 5};

    // 使用std::move将myVec转换为右值引用，准备转移资源
    vector<int> movedVec = std::move(myVec);

    // 输出movedVec内容，验证资源是否成功转移
    cout << "Moved vector content: ";
    for (int num : movedVec)
    {
        cout << num << " ";
    }
    cout << endl;

    // 输出myVec的内容，验证它已被清空
    cout << "Original vector after move: ";
    for (int num : myVec)
    {
        cout << num << " "; // 这里会输出空，因为资源已被转移
    }
    cout << endl;

    return 0;
}