/*
 * @lc app=leetcode.cn id=1599 lang=cpp
 *
 * [1599] 经营摩天轮的最大利润
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  int minOperationsMaxProfit(vector<int>& customers, int boardingCost,
                             int runningCost) {
    int a = 0, b = 0, n = customers.size();
    int res = INT_MIN;
    int ans = -1;
    for (int i = 0; i < n || b != 0; i++) {
      if (i < n) b += customers[i];
      a += min(b, 4);
      b -= min(b, 4);
      int t = a * boardingCost - (i + 1) * runningCost;
      if (t > res) res = t, ans = i + 1;
    }
    return res < 0 ? -1 : ans;
  }
};
// @lc code=end
