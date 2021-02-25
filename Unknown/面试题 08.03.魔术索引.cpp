/*
* @lc app=leetcode.cn id=面试题 08.03 lang=cpp
*
* [面试题 08.03] 魔术索引
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
public:
    int findMagicIndex(vector<int>& nums) {
        auto n = nums.size();
        for(auto i = 0;i<n;i++)
            if(nums[i]==i)
                return i;
        return -1;
    }
};
// @lc code=end

