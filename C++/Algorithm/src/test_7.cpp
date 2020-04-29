/*
求 1+2+...+n ，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。

 

示例 1：

输入: n = 3
输出: 6
示例 2：

输入: n = 9
输出: 45

*/

#include <iostream>

using namespace std;

class Solution
{
public:
    int sumNums(int n)
    {
        static int sum = 0 ;
        
        (n > 1) && sumNums(n-1); //递归函数，要确定结束条件

        sum += n;
        return sum;
    }
};

int main(int argc, char **argv)
{
    cout << "Please input a number:" << endl;

    int a = 0;

    cin >> a;

    Solution sol;
    cout << "The result is:" << sol.sumNums(a) << endl;

    return -1;
}


/*
短路效应：
 if(A && B)  // 若 A 为 false ，则 B 的判断不会执行（即短路），直接判定 A && B 为 false
 if(A || B) // 若 A 为 true ，则 B 的判断不会执行（即短路），直接判定 A || B 为 true
*/