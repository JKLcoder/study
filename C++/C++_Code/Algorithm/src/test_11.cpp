/*
输入整数数组 arr ，找出其中最小的 k 个数。例如，输入4、5、1、6、2、7、3、8这8个数字，则最小的4个数字是1、2、3、4。

示例 1：

输入：arr = [3,2,1], k = 2
输出：[1,2] 或者 [2,1]
示例 2：

输入：arr = [0,1,2,1], k = 1
输出：[0]
*/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<int> getLeastNumbers(vector<int> &arr, int k)
    {
        vector<int> vec;
        sort(arr.begin(), arr.end());
        for (int i = 0; i < k; ++i)
            vec.push_back(arr[i]);
        return vec;
    }
};

int main(int argc, char **argv)
{
    vector<int> array{0, 1, 2, 1};

    cout << "Please input a number:" << endl;

    int a;
    cin >> a;

    Solution sol;
    vector<int> vec = sol.getLeastNumbers(array, a);
    cout << "The numbers is:" << endl;
    for (int num : vec)
        cout << num << endl;

    return -1;
}

/*
总结：这道题的想法是首先要先排序，这是必然的；
*/
