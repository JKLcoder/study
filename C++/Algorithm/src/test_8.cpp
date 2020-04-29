/*
写一个程序，输出从 1 到 n 数字的字符串表示。

1. 如果 n 是3的倍数，输出“Fizz”；

2. 如果 n 是5的倍数，输出“Buzz”；

3.如果 n 同时是3和5的倍数，输出 “FizzBuzz”。
*/

#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;

//这种方式符合审判者设计模式，否则多重联合判断将会使问题变的很复杂
class Solution
{
public:
    vector<string> fizzBuzz(int n)
    {
        vector<string> vec;
        for (int i = 1; i <= n; ++i)
        {
            bool bDelivedBy3 = (i % 3 == 0) ? true : false;
            bool bDelivedBy5 = (i % 5 == 0) ? true : false;

            string str;
            if (bDelivedBy3)
                str += "Fizz";

            if (bDelivedBy5)
                str += "Buzz";

            if (str.empty())
                vec.push_back(to_string(i));  //to_string,将数字转化为字符串
            else
                vec.push_back(str);

        }
        return vec;
    }
};

int main(int argc, char **argv)
{
    int a;
    cout << "Please input a number:" << endl;
    cin >> a;

    Solution sol;
    vector<string> str = sol.fizzBuzz(a);
    for (string s : str)
        cout << s << endl;

    return -1;
}
