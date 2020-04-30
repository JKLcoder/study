/*
统计一个数字在排序数组中出现的次数。

示例 1:

输入: nums = [5,7,7,8,8,10], target = 8
输出: 2

示例 2:

输入: nums = [5,7,7,8,8,10], target = 6
输出: 0

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int count = nums.size();
        if (count == 0 || target < nums[0] || target > nums[count - 1])
            return 0;

        int a = 0;
        for (int num : nums)
        {
            if (num == target)
                a++;
            else if (num < target)
                continue;
            else if (num > target)
                break;
        }

        return a;
    }
};

int main(int argc, char **agrv)
{
    vector<int> vec{5,7,7,8,8,10};

    Solution sol;

    cout << "The num is :" << sol.search(vec,8) << endl;

    return -1;
}

