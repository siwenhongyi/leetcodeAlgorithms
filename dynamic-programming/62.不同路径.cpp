/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */
#include "head.h"
using namespace std;
// @lc code=start
class Solution
{
public:
    int uniquePaths(int n, int m)
    {
        vector<int> first(m), second(m);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                if (i == 0 || j == 0)
                    second[j] = 1;
                else
                    second[j] = second[j - 1] + first[j];
            first.swap(second);
        }
        return first.back();
    }
};
// @lc code=end
