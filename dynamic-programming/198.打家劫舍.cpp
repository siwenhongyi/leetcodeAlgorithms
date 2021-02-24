/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */
#include "head.h"
// @lc code=start
class Solution {
 public:
  int rob(vector<int>& nums) {
    int n = nums.size();
    if (n < 2) {
      int res = 0;
      for (auto& it : nums) res = max(res, it);
      return res;
    }
    vector<int> dp(n, 0);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for (int i = 2; i < n; i++) {
      dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
    }
    return dp.back();
  }
};
// @lc code=end
