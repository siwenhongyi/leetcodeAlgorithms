/*
* @lc app=leetcode.cn id=560 lang=cpp
*
* [560] 和为K的子数组
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> s(n + 1,0);
        for (int i = 0; i < n; i++)
            s[i + 1] = s[i] + nums[i];
        int res = 0;
        for(int i = 0;i<=n;i++)
            for (int j = i + 1; j <= n; j++) 
                if (s[j] - s[i] == k)
                    res++;
        return res;
    }
};
// @lc code=end

