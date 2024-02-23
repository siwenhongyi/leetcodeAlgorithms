/*
 * @lc app=leetcode.cn id=1449 lang=cpp
 *
 * [1449] 数位成本和为目标值的最大数字
 */
#include "head.h"
using namespace std;

// @lc code=start
class Solution {
 public:
  string largestNumber(vector<int>& cost, int target) {
    vector<vector<int>> dp(10, vector<int>(target + 1, 1 << 31));
    vector<vector<int>> f(10, vector<int>(target + 1, 1 << 31));
    dp[0][0] = 0;
    int o, j;
    for (int i = 1; i < 10; i++) {
      o = cost[i - 1];
      for (j = 0; j <= target; j++) {
        if (j < o) {
          dp[i][j] = dp[i - 1][j];
          f[i][j] = j;
        } else {
          if (dp[i][j - o] + 1 >= dp[i - 1][j]) {
            dp[i][j] = dp[i][j - o] + 1;
            f[i][j] = j - o;
          } else {
            dp[i][j] = dp[i - 1][j];
            f[i][j] = j;
          }
        }
      }
    }
    if (dp[9][target] < 0) return "0";
    string res;
    o = 9, j = target;
    while (o > 0) {
      if (j == f[o][j])
        o--;
      else {
        res += '0' + o;
        j = f[o][j];
      }
    }
    return res;
  }
};
// @lc code=end
