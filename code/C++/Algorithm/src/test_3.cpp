/*
请实现一个函数，把字符串 s 中的每个空格替换成"%20"。

示例 1：

输入：s = "We are happy."
输出："We%20are%20happy."
*/

#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    string replaceSpace(string s)
    {
        string temp;
        int size = s.size();
        for (int i = 0; i < size; ++i)
        {
            char c = s.at(i);
            if (c == ' ')
                temp.append("%20");
            else
                temp.push_back(c);
        }

        return temp;
    }
};

int main(int argc, char **argv)
{
    string s = "We are happy.";

    // cout << "please input a string:" << endl;
    // cin >> s;

    Solution sol;
    string temp = sol.replaceSpace(s);
    cout << temp;

    return -1;
}