/*
 * @lc app=leetcode.cn id=376 lang=cpp
 *
 * [376] 摆动序列
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution
{
public:
    int wiggleMaxLength(vector<int> &nums)
    {
        int n = nums.size();
        if (n < 2)
            return n;
        vector<int> up(n, 1), down(n, 1);
        int u, d;
        int res = 1;
        for (int i = 1; i < n; i++)
        {
            u = d = 1;
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                    u = max(u, down[j] + 1);
                else if (nums[i] < nums[j])
                    d = max(d, up[j] + 1);
            }
            res = max(res, max(u, d));
            up[i] = u, down[i] = d;
        }
        return res;
    }
};
// @lc code=end
