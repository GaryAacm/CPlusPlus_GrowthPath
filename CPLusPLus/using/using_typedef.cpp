#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> v1;
using v2 = vector<int>;
//两种定义格式

int main()
{
    int nums1[] = {1, 2, 3, 4, 5, 6};
    //使用迭代器范围构造vector
    //v1 是类型，vec1 是对象
    v1 vec1(nums1, nums1 + sizeof(nums1) / sizeof(int));
    int nums2[] = {5, 7, 6};
    v2 vec2(nums2, nums2 + sizeof(nums2) / sizeof(int));

    for (auto i : vec1)
        cout << i << " ";
    cout << endl;

    for (auto i : vec2)
        cout << i << " ";
    cout << endl;

    return 0;
}