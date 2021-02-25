/*
 * @lc app=leetcode.cn id=583 lang=cpp
 *
 * [583] 两个字符串的删除操作
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  int minDistance(string word1, string word2) {
    int n = word1.size(), m = word2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    int res = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (word1[i - 1] == word2[j - 1])
          dp[i][j] = dp[i - 1][j - 1] + 1;
        else
          dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        res = max(res, dp[i][j]);
      }
    }
    return n + m - res * 2;
  }
};
// @lc code=end
