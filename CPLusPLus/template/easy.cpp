#include <iostream>
#include <string>

template <typename T>
T max(T a, T b)
{
    return a > b ? a : b;
}

template <typename P, int size>
P sum(P (&arr)[size])
{
    P total = 0;
    for (int i = 0; i < size; i++)
    {
        total += arr[i];
    }
    return total;
}

// 多类型参数的模板函数
template <typename T, typename U>
void printPair(const T &first, const U &second)
{
    std::cout << first << " " << second << std::endl;
}

int main()
{
    std::cout << max(3, 5) << std::endl;
    std::cout << max(3.2, 2.9) << std::endl; // 输出 3.2 (double)
    std::cout << max('a', 'z') << std::endl;

    int intArr[] = {1, 2, 3, 4, 5};
    double doubleArr[] = {1.1, 2.2, 3.3};

    std::cout << "Sum of int array: " << sum(intArr) << std::endl;
    std::cout << "Sum of double array: " << sum(doubleArr) << std::endl; // 输出 'z' (char)

    printPair(1, 3.14);                       // (1, 3.14)
    printPair("Hello", std::string("World")); // (Hello, World)
    printPair('A', 65);                       // (A, 65)

    return 0;
}