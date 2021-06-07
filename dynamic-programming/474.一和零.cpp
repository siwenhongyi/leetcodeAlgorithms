/*
 * @lc app=leetcode.cn id=474 lang=cpp
 *
 * [474] 一和零
 */
#include "head.h"
// @lc code=start
class Solution {
 public:
  int findMaxForm(vector<string>& strs, int m, int n) {
    int w, v, sz = strs.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < sz; ++i) {
      w = v = 0;
      for (auto& it : strs[i])
        if (it == '0')
          ++w;
        else
          ++v;
      for (int j = m; j >= w; --j) {
        for (int k = n; k >= v; --k)
          dp[j][k] = max(dp[j][k], dp[j - w][k - v] + 1);
      }
    }
    return dp.back().back();
  }
};
// @lc code=end
