/*
 * @lc app=leetcode.cn id=2110 lang=cpp
 *
 * [2110] 股票平滑下跌阶段的数目
 */

#include "head.h"
using namespace std;

// @lc code=start
class Solution {
  using ll = long long;

 public:
  long long getDescentPeriods(vector<int>& p) {
    ll length = 1, res = 1;
    int n = p.size();
    for (int i = 1; i < n; i++) {
      if (p[i] == p[i - 1] - 1)
        length++;
      else {
        length = 1;
      }
      res += length;
    }
    return res;
  }
};
// @lc code=end
