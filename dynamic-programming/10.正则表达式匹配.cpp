/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */
#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  bool isMatch(string s, string p) {
    int n = s.size(), m = p.size();
    auto matches = [&](int i, int j) {
      return i > 0 && (p[j - 1] == '.' || p[j - 1] == s[i - 1]);
    };
    vector<vector<int>> dp(n + 1, vector(m + 1, 0));
    dp[0][0] = 1;
    for (int i = 0; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (p[j - 1] == '*') {
          dp[i][j] |= dp[i][j - 2];
          if (matches(i, j - 1)) {
            dp[i][j] |= dp[i - 1][j];
          }
        } else if (matches(i, j)) {
          dp[i][j] |= dp[i - 1][j - 1];
        }
      }
    }
    return dp.back().back();
  }
};
// @lc code=end
