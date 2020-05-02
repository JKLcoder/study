/*
请实现一个函数，输入一个整数，输出该数二进制表示中 1 的个数。例如，把 9 表示成二进制是 1001，有 2 位是 1。因此，如果输入 9，则该函数输出 2。

示例 1：

输入：00000000000000000000000000001011
输出：3
解释：输入的二进制串 00000000000000000000000000001011 中，共有三位为 '1'。
示例 2：

输入：00000000000000000000000010000000
输出：1
解释：输入的二进制串 00000000000000000000000010000000 中，共有一位为 '1'。
示例 3：

输入：11111111111111111111111111111101
输出：31
解释：输入的二进制串 11111111111111111111111111111101 中，共有 31 位为 '1'。
*/
#include <iostream>

using namespace std;

class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int sum = 0;
        for (int i = 0; i < 32; ++i)
        {
            if ((n>>i)%2)
                sum++;
        }
        return sum;
    }
};

int main(int argc, char **argv)
{
    int n;

    cout << "Please input a number:" << endl;
    cin >> n;

    Solution sol;
    cout << "The weight is:" << sol.hammingWeight(n) << endl;

    return -1;
}

/*
虽然上述算法也能满足要求，但是个人感觉还是存在缺陷：
 1.这里我把target当做int型，也就是32位，但是如果不是int型呢？
 2.使用取余，不够高明！

下面方法更好：

class Solution:
    def hammingWeight(self, n: int) -> int:
        res = 0
        while n:
            res += n & 1
            n >>= 1
        return res

*/
