/*
 * @lc app=leetcode.cn id=115 lang=cpp
 *
 * [115] 不同的子序列
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  int numDistinct(string s, string t) {
    int n = s.size(), m = t.size();
    vector<vector<unsigned int>> dp(n + 1, vector<unsigned int>(m + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) dp[i][0] = 1;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        dp[i][j] = dp[i - 1][j] + (s[i - 1] == t[j - 1] ? dp[i - 1][j - 1] : 0);
      }
    }
    return dp.back().back();
  }
};
// @lc code=end
