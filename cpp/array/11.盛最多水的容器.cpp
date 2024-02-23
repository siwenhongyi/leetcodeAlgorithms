/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */
#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  int maxArea(vector<int>& s) {
    if (s.size() == 2) return min(s[0], s[1]);
    int l = 0, r = s.size() - 1, res = 0;
    while (l < r) {
      auto&& h = min(s[l], s[r]);
      res = max(res, (r - l) * h);
      if (s[l] < s[r])
        l++;
      else
        r--;
    }
    return res;
  }
};
// @lc code=end
