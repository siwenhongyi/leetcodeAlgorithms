/*
 * @lc app=leetcode.cn id=57 lang=cpp
 *
 * [57] 插入区间
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  vector<vector<int>> insert(vector<vector<int>>& arrs, vector<int>& target) {
    int n = arrs.size();
    if (!n) return {target};
    vector<vector<int>> res;
    int a, b, i, flag = 1;
    a = arrs[0][0], b = arrs[0][1];
    if (target[0] < a)
      a = target[0], b = target[1], i = 0, flag = 0;
    else
      i = 1;
    while (i < n) {
      auto bg = arrs[i][0], en = arrs[i][1];
      if (flag && target[0] <= bg) {
        bg = target[0], en = target[1], flag = 0;
        i--;
      }
      if (bg > b) {
        res.push_back({a, b});
        a = bg, b = en;
      } else
        b = max(b, en);
      i++;
    }
    if (flag) {
      if (target[0] <= b)
        b = max(b, target[1]);
      else {
        res.push_back({a, b});
        a = target[0], b = target[1];
      }
    }
    res.push_back({a, b});
    return res;
  }
};
// @lc code=end
