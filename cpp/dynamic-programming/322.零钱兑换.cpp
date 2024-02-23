/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */
#include "head.h"
// @lc code=start
class Solution {
 public:
  int coinChange(vector<int>& c, int tar) {
    vector<int> dp(tar + 1, (1 << 30));
    dp[0] = 0;
    for (int i = 1; i <= tar; ++i) {
      for (auto& it : c) {
        if (i >= it) dp[i] = min(dp[i], dp[i - it] + 1);
      }
    }
    return dp.back() > tar ? -1 : dp.back();
  }
};
// @lc code=end
