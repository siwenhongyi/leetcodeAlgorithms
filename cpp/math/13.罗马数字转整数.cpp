/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  int romanToInt(string s) {
    if (s.empty()) return 0;
    int i = 0, n = s.size(), res = 0;
    while (i < n) {
      if (s[i] == 'M')
        res += 1000;
      else if (s[i] == 'D')
        res += 500;
      else if (s[i] == 'C') {
        if (i + 1 < n && s[i + 1] == 'M') {
          i++;
          res += 900;
        } else if (i + 1 < n && s[i + 1] == 'D') {
          i++;
          res += 400;
        } else
          res += 100;
      } else if (s[i] == 'L')
        res += 50;
      else if (s[i] == 'X') {
        if (i + 1 < n && s[i + 1] == 'L') {
          i++;
          res += 40;
        } else if (i + 1 < n && s[i + 1] == 'C') {
          i++;
          res += 90;
        } else
          res += 10;
      } else if (s[i] == 'V')
        res += 5;
      else {
        if (i + 1 < n && s[i + 1] == 'V') {
          i++;
          res += 4;
        } else if (i + 1 < n && s[i + 1] == 'X') {
          i++;
          res += 9;
        } else
          res += 1;
      }
      i++;
    }
    return res;
  }
};
// @lc code=end
