/*
 * @lc app=leetcode.cn id=452 lang=cpp
 *
 * [452] 用最少数量的箭引爆气球
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  int findMinArrowShots(vector<vector<int>>& p) {
    if (p.size() <= 1) return p.size();
    int res = 0;
    sort(p.begin(), p.end());
    int a = p[0][0], b = p[0][1];
    for (int i = 1; i < p.size(); i++) {
      if (p[i][0] <= b) {
        a = max(a, p[i][0]), b = min(b, p[i][1]);
      } else {
        res++;
        a = p[i][0], b = p[i][1];
      }
    }
    return res + 1;
  }
};
// @lc code=end
