/*
 * @lc app=leetcode.cn id=87 lang=cpp
 *
 * [87] 扰乱字符串
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  bool isScramble(string s, string t) {
    int n = s.size();
    vector<vector<vector<bool>>> dp(n, vector(n, vector(n + 1, false)));
    for (int i = n - 1; i >= 0; i--) {
      for (int j = n - 1; j >= 0; j--) {
        dp[i][j][1] = s[i] == t[j];
        for (int k = 2; k <= min(n - i, n - j); k++) {
          for (int length = 1; length < k && !dp[i][j][k]; length++) {
            dp[i][j][k] =
                (dp[i][j][length] && dp[i + length][j + length][k - length]) ||
                (dp[i][j + k - length][length] &&
                 dp[i + length][j][k - length]);
          }
        }
      }
    }
    return dp[0][0][n];
  }
};
// @lc code=end
