/*
 * @lc app=leetcode.cn id=518 lang=cpp
 *
 * [518] 零钱兑换 II
 */

// @lc code=start
class Solution {
 public:
  int change(int n, vector<int>& coins) {
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (auto& it : coins)
      for (int i = it; i <= n; i++) dp[i] += dp[i - it];
    return dp.back();
  }
};
// @lc code=end
