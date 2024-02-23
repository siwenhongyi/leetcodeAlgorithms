/*
 * @lc app=leetcode.cn id=520 lang=cpp
 *
 * [520] 检测大写字母
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  bool D(string s) {
    for (auto &i : s)
      if (i >= 'a' && i <= 'z') return false;
    return true;
  }
  bool X(string s) {
    for (auto &i : s)
      if (i >= 'A' && i <= 'Z') return false;
    return true;
  }
  bool detectCapitalUse(string s) {
    if (s.size() <= 1) return true;
    if (s[0] >= 'A' && s[0] <= 'Z') return D(s.substr(1)) || X(s.substr(1));
    return X(s.substr(1));
  }
};
// @lc code=end
