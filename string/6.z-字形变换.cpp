/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */
#include "head.h"
// @lc code=start
class Solution {
 public:
  string convert(string s, int numRows) {
    if (numRows == 1) return s;
    string res;
    vector<string> pos(numRows);
    int i = 0, ix = 1;
    for (auto& it : s) {
      pos[i].push_back(it);
      i += ix;
      if (i == numRows) {
        i = numRows - 2, ix = -1;
      }
      if (i == -1) {
        i = 1, ix = 1;
      }
    }
    for (auto& it : pos)
      for (auto& iter : it) {
        res.push_back(iter);
      }
    return res;
  }
};
// @lc code=end
