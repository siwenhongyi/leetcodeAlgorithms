/*
* @lc app=leetcode.cn id=164 lang=cpp
*
* [164] 最大间距
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size()<2)return 0;
        sort(nums.begin(),nums.end());
        int res = 0;
        for(int i = 1;i<nums.size();i++)
            res = max(res,abs(nums[i]-nums[i-1]));
        return res;
    }
};
// @lc code=end

