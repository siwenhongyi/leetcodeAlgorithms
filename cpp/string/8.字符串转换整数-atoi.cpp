/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */
#include "head.h"
// @lc code=start
class Solution {
 public:
  int myAtoi(string s) {
    int res = 0;
    bool op = false, a, b;
    a = b = true;
    int t = INT_MAX / 10;
    for (auto& it : s) {
      if (it >= '0' && it <= '9') {
        a = b = false;
        if (res > t || (res == t && it > '0' + 7)) {
          return op ? INT_MIN : INT_MAX;
        }
        res = res * 10 + (it - '0');
      } else if (a && (it == '-' || it == '+')) {
        a = b = false;
        op = it == '-';
      } else if (b && it == ' ')
        continue;
      else {
        return op ? -res : res;
      }
    }
    return op ? -res : res;
  }
};
// @lc code=end
