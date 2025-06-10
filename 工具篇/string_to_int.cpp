#include <iostream>
#include <string>

#include <sstream>
using namespace std;

string str = "16s";
int a = atoi(str.c_str());
int b = strtol(str.c_str(), NULL, 10);
int c = strtol(str.c_str(), nullptr, 8); // 8进制
// 这两个函数都是从字符串开始寻找数字或者正负号或者小数点,遇到非法字符终止。
// 没有数字的时候输出0

// 自定义，用流的写入和写出巧妙转化
float stringToInt(const string &str)
{
    float v;
    stringstream ss;
    ss << str;
    ss >> v; //从 stringstream 中读取数据
    return v;
}

int main()
{
    string str1 = "asq";
    // int a1 = stoi(str1);//出现异常
    string str2 = "12312";
    int cc = stoi(str2);

    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
    cout << cc << endl;

    float i = stringToInt("2.3");
    cout<<i<<endl;

    return 0;
}
