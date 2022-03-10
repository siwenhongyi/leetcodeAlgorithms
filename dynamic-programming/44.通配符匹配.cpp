/*
 * @lc app=leetcode.cn id=44 lang=cpp
 *
 * [44] 通配符匹配
 */
#include "head.h"
using namesapce std;
// @lc code=start
class Solution {
 public:
  bool isMatch(string s, string p) {
    if (!p.size()) return !s.size();
    //if (p.size() && p[0] == '*') return false;
    int size_s = s.size(), size_p = p.size();
    vector<vector<bool>> pos(size_s + 1, vector<bool>(size_p + 1, false));
    pos[0][0] = true;
    for (int i = 0; i < size_p; i++)
      if (p[i] == '*') pos[0][i + 1] = true; else break;
    for (int i = 0; i < size_s; i++) {
      for (int j = 0; j < size_p; j++) {
        if (p[j] == '*') {
            pos[i + 1][j + 1] =
                pos[i][j + 1] || pos[i + 1][j];
        }
        else  if (s[i] == p[j] || p[j] == '?')
          pos[i + 1][j + 1] = pos[i][j];
      }
    }
    return pos[size_s][size_p];
  }
};
// @lc code=end

