/*
 * @lc app=leetcode.cn id=132 lang=cpp
 *
 * [132] 分割回文串 II
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  int minCut(string s) {
    int n = s.size(), res = (1 << 30);
    vector<vector<int>> dp(n, vector(n, 0));
    dp.resize(n, vector(n, 0));
    for (int i = 0; i < n; i++) dp[i][i] = 1;
    for (int i = n - 1; i >= 0; i--) {
      for (int j = i + 1; j < n; j++) {
        if (j == i + 1)
          dp[i][j] = s[i] == s[j];
        else
          dp[i][j] = int(s[i] == s[j] && dp[i + 1][j - 1]);
      }
    }
    vector<int> ans(n, 0);
    for (int i = 0; i < n; i++) {
      if (dp[0][i]) {
        ans[i] = 0;
        continue;
      }
      ans[i] = i;
      for (int j = 0; j < i; j++) {
        if (dp[0][j] && dp[j + 1][i]) {
          ans[i] = min(ans[i], ans[j] + 1);
        }
      }
    }
    return res - 1;
  }
};
// @lc code=end
