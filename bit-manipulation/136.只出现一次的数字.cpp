/*
* @lc app=leetcode.cn id=136 lang=cpp
*
* [136] 只出现一次的数字
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(auto &i:nums)
            res^=i;
        return res;
    }
};
// @lc code=end

