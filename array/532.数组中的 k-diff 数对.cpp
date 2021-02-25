/*
* @lc app=leetcode.cn id=532 lang=cpp
*
* [532] 数组中的 k-diff 数对
*/

#include"head.h"
using namespace std;
// @lc code=start

class Solution
{
public:
    int findPairs(vector<int> &nums, int k)
    {
        unordered_map<int, int> pos;
        for (auto &it : nums)
            pos[it]++;
        int res = 0;
        if (k == 0)
        {
            for (auto &it : pos)
                res += it.second > 1;
        }
        else
        {
            for (auto &it : pos)
            {
                it.second--;
                if (pos.count(it.first + k))
                    res++;
            }
        }
        return res;
    }
};
// @lc code=end

