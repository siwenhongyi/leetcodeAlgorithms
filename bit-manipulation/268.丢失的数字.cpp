/*
* @lc app=leetcode.cn id=268 lang=cpp
*
* [268] 丢失的数字
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
public:
	int missingNumber(vector<int>& nums) {
        int res = 0,n=nums.size();
        for(int i = 0;i<=n;i++)
            res^=i;
        for(auto &i:nums)
            res^=i;
        return res;
	}
};

// @lc code=end

