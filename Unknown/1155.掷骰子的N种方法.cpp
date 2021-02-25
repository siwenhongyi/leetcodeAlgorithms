/*
 * @lc app=leetcode.cn id=1155 lang=cpp
 *
 * [1155] 掷骰子的N种方法
 */

#include "head.h"
using namespace std;
// @lc code=start

class Solution {
 public:
  long long int numRollsToTarget(int d, int f, int target) {
    if (target > d * f || target < d) return 0;
    vector<vector<long long int> > dp(d + 1,
                                      vector<long long int>(f * d + 1, 0));
    for (int i = 1; i <= f; i++) {
      dp[1][i] = 1;
    }
    for (int i = 2; i <= d; i++) {
      for (int k = i; k <= min(f * i, target); k++) {
        int x = 1;
        while (x <= f && k - x >= 0) {
          dp[i][k] += dp[i - 1][k - x];
          x++;
        }
        dp[i][k] %= 1000000007;
      }
    }
    return dp[d][target];
  }
};
// @lc code=end
