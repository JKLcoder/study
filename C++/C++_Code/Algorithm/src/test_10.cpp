/*
输入数字 n，按顺序打印出从 1 到最大的 n 位十进制数。比如输入 3，则打印出 1、2、3 一直到最大的 3 位数 999。

示例 1:

输入: n = 1
输出: [1,2,3,4,5,6,7,8,9]
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int getDigit(int n)
    {
        int count = 0;
        int num = n / 10;
        while (num)
        {
            num = num / 10;
            count++;
        }

        return (count+1);
    }

    vector<int> printNumbers(int n)
    {
        vector<int> vec;

        int num = 1;
        while (getDigit(num) <= n)
        {
            vec.push_back(num);
            num++;
        }

        return vec;
    }
};

int main(int argc, char **argv)
{
    cout << "Please input a number:" << endl;
    int a;
    cin >> a;

    Solution sol;
    cout << "The num is:" << sol.getDigit(a) << endl;
    
    return -1;
}

/*
总结：看了一下答案，使用pow（10，n）获取n位数的最大值更简单；
*/