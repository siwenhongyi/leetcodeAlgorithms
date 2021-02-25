/*
 * @lc app=leetcode.cn id=495 lang=cpp
 *
 * [495] 提莫攻击
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  int findPoisonedDuration(vector<int>& t, int p) {
    if (!p || t.empty()) return 0;
    int res = 0, n = t.size();
    int st = t.front(), en = st + p;
    for (int i = 1; i < n; i++) {
      if (t[i] >= en)
        res += p;
      else
        res += t[i] - st;
      st = t[i];
      en = st + p;
    }
    return res + p;
  }
};

// @lc code=end
