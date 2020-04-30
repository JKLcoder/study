/*
数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。

你可以假设数组是非空的，并且给定的数组总是存在多数元素。

示例 1:

输入: [1, 2, 3, 2, 2, 2, 5, 4, 2]
输出: 2
*/

#include <vector>
#include <iostream>
#include <map>

using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        map<int, int> mp;

        for (int num : nums)
        {
            if (mp.find(num) != mp.end()) //mp中存在
                mp[num] = mp[num] + 1;
            else
                mp[num] = 1;
        }

        int count = nums.size();

        map<int, int>::const_iterator iter = mp.begin();
        while (iter != mp.end())
        {
            if (iter->second > count / 2)
                return iter->first;
            iter++;
        }

        return -1;
    }
};

int main(int argc, char **argv)
{
    vector<int> vec{1, 2, 3, 2, 2, 2, 5, 4, 2};

    Solution sol;
    int num = sol.majorityElement(vec);
    cout << "The num is:" << num <<endl;

    return -1;
}
