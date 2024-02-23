/*
 * @lc app=leetcode.cn id=1217 lang=cpp
 *
 * [1217] 玩筹码
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  int minCostToMoveChips(vector<int>& x) {
    int o, e;
    o = e = 0;
    for (auto& i : x)
      if (i % 2)
        o++;
      else
        e++;
    return min(o, e);
  }
};
// @lc code=end
