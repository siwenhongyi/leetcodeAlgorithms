/*
 * @lc app=leetcode.cn id=65 lang=cpp
 *
 * [65] 有效数字
 */

#include "head.h"
using namespace std;
// @lc code=start

class Solution {
 public:
  bool check(string s, int x) {
    int num = 0;
    int i = 0, j = s.size() - 1;
    if (s[i] == '+' || s[i] == '-') i++;
    while (i <= j) {
      if (s[i] >= '0' && s[i] <= '9')
        num++;
      else if (s[i] == '.') {
        if (!x)
          x++;
        else
          return false;
      } else if (s[i] == '+' || s[i] == '-')
        return false;
      else
        return false;
      i++;
    }
    return num > 0;
  }
  bool isNumber(string s) {
    auto iter = s.begin();
    while (iter != s.end() && *iter == ' ') iter = s.erase(iter);
    if (!s.size()) return false;
    iter = s.end() - 1;
    while (s.size() > 0 && *iter == ' ') iter = s.erase(iter) - 1;
    auto it = s.find_first_of('e');
    bool l, r;
    if (it == 0) return false;
    if (it != s.npos) {
      l = check(string(s.begin(), s.begin() + it), 0);
      r = check(string(s.begin() + it + 1, s.end()), 1);
    } else {
      return check(s, 0);
    }
    return l && r;
  }
};

// @lc code=end
