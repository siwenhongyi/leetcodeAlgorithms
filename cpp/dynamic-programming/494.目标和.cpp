/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */
#include "head.h"
// @lc code=start
class Solution {
 public:
  int findTargetSumWays(vector<int>& nums, int target) {
    int sum = 0;
    for (auto& it : nums) sum += it;
    if (sum < target || (sum - target) % 2) return 0;
    int n = nums.size(), m = (sum - target) / 2, t;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j <= m; ++j) {
        t = nums[i - 1];
        if (t > j)
          dp[i][j] = dp[i - 1][j];
        else
          dp[i][j] = dp[i - 1][j] + dp[i - 1][j - t];
      }
    }
    return dp.back().back();
  }
};
// @lc code=end
