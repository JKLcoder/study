/*
找出数组中重复的数字。
在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。
示例 1：
输入：
[2, 3, 1, 0, 2, 5, 3]
输出：2 或 3 
*/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

// class Solution
// {
// public:
//     int findRepeatNumber(vector<int> &nums)
//     {
//         int num = -1;
//         int size = nums.size();

//         for (int i = 0; i < size; ++i)
//         {
//             int a = nums[i]; //要找重复数字的数字
//             for (int j = i + 1; j < size; ++j)
//             {

//                 if (a == nums[j])
//                 {
//                     num = a;
//                     break;
//                 }
//             }
//         }
//         return num;
//     }
// };
// 该方式速度太慢

//思路：遍历过程中，如果该数字不存在于该列表中，则加入列表，如果已存在，则表明该数字重复；
class Solution
{
public:
    int findRepeatNumber(vector<int> &nums)
    {
        map<int, int> mp;
        int num = -1;
        int size = nums.size();

        for (int i = 0; i < size; ++i)
        {
            int a = nums[i];

            if (mp.find(a) != mp.end())
                return a;
            else
                mp[a] = a;
        }

        return num;
    }
};

int main(int argc, char **argv)
{
    vector<int> vec;

    while (vec.size() < 10)
    {
        int a;
        cout << "Please input a number:" << endl;
        cin >> a;
        vec.push_back(a);
    }

    Solution sol;
    int num = sol.findRepeatNumber(vec);
    if (num == -1)
        cout << "There is no number repeat!";
    else
        cout << "The repeat number is :" << num;

    return -1;
}