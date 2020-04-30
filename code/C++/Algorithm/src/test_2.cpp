/*
在一个 n * m 的二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

示例:

现有矩阵 matrix 如下：
[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
给定 target = 5，返回 true。
给定 target = 20，返回 false。
*/

#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    bool findNumberIn2DArray(vector<vector<int>> &matrix, int target)
    {
        for (int i = 0; i < matrix.size(); ++i)
        {
            vector<int> vec = matrix[i];
            for (int j = 0; j < vec.size(); ++j)
            {
                if (target == vec[j])
                    return true;
            }
        }
        return false;
    }
};

int main(int argc, char **argv)
{
    vector<vector<int>> mat;

    // for (int i = 0; i < 5; ++i)
    // {
    //     vector<int> vec;
    //     for (int j = 0; j < 5; ++j)
    //     {
    //         int a;
    //         cin >> a;
    //         vec.push_back(a);
    //     }
    //     mat.push_back(vec);
    // }

    vector<int> vec1{1, 4, 7, 11, 15};
    vector<int> vec2{2, 5, 8, 12, 19};
    vector<int> vec3{3, 6, 9, 16, 22};
    vector<int> vec4{10, 13, 14, 17, 24};
    vector<int> vec5{18, 21, 23, 26, 30};

    mat.push_back(vec1);
    mat.push_back(vec2);
    mat.push_back(vec3);
    mat.push_back(vec4);
    mat.push_back(vec5);

    cout << "Please input a number:" << endl;

    int b;
    cin >> b;

    Solution sol;

    if (sol.findNumberIn2DArray(mat, b))
        cout << "find the number!";
    else
        cout << "not find!";

    return -1;
}