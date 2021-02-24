/*
 * @lc app=leetcode.cn id=221 lang=cpp
 *
 * [221] 最大正方形
 */
#include "head.h"
// @lc code=start
class Solution {
 public:
  int maximalSquare(vector<vector<char>>& mat) {
    if (mat.size() == 1)
      return find(mat[0].begin(), mat[0].end(), '1') != mat[0].end();
    int n = mat.size(), m = mat[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));
    int res = 0, pre, flag;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (mat[i][j] == '0') continue;
        dp[i][j] = 1;
        res = max(res, dp[i][j]);
        if (i * j == 0) continue;
        pre = dp[i - 1][j - 1];
        if (pre) {
          flag = 0;
          for (int k = 1; k <= pre; k++) {
            if (dp[i][j - k] == 0 || dp[i - k][j] == 0) break;
            flag++;
          }
          dp[i][j] += flag;
        }
        res = max(res, dp[i][j]);
      }
    }
    return res * res;
  }
};
// @lc code=end
