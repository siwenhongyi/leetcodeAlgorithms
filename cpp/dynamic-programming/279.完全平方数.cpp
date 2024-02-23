/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */
#include "head.h"
using namespace std;

// @lc code=start
class Solution {
 public:
  bool fun_pow(int x) {
    int t = sqrt(x);
    return t * t == x;
  }
  bool fun_four(int x) {
    while (x % 4 == 0) x /= 4;
    return x % 8 == 7;
  }
  int numSquares(int n) {
    // math
    if (fun_pow(n)) return 1;
    if (fun_four(n)) return 4;
    for (int i = 1; i * i < n; i++)
      if (fun_pow(n - i * i)) return 2;
    return 3;

    // dp
    vector<int> dp(n + 1, 0);
    int t;
    for (int i = 1; i <= n; i++) {
      t = 1 << 30;
      for (int j = 1; j * j <= i; j++) {
        t = min(t, dp[i - j * j]);
      }
      dp[i] = t + 1;
    }
    return dp.back();
  }
};
// @lc code=end
