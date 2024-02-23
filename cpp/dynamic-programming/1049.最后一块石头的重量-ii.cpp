/*
 * @lc app=leetcode.cn id=1049 lang=cpp
 *
 * [1049] 最后一块石头的重量 II
 */
#include "head.h"
// @lc code=start
class Solution {
 public:
  int lastStoneWeightII(vector<int>& stones) {
    int sum = accumulate(stones.begin(), stones.end(), 0);
    int n = stones.size(), m = sum / 2;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j <= m; ++j) {
        dp[i][j] = j >= stones[i - 1]
                       ? max(dp[i - 1][j],
                             dp[i - 1][j - stones[i - 1]] + stones[i - 1])
                       : dp[i - 1][j];
      }
    }
    return sum - 2 * dp.back().back();
  }
};
// @lc code=end
