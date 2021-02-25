/*
* @lc app=leetcode.cn id=217 lang=cpp
*
* [217] 存在重复元素
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_set<int> pos;
        for (auto &it : nums)
            if (pos.count(it))
                return true;
            else
                pos.insert(it);
        return false;
    }
};
// @lc code=end

