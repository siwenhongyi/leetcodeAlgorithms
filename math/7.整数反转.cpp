/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */
#include "head.h"
// @lc code=start
class Solution {
 public:
  int reverse(int x) {
    bool op = false;
    int res;
    res = 0;
    if (x < 0) {
      if (x == INT_MIN) return 0;
      op = true;
      x = -x;
    }
    int t = INT_MAX / 10;
    while (x) {
      if (res > t || (res == t && x % 10 > 7)) return 0;
      res = res * 10 + (x % 10);
      x /= 10;
    }
    return op ? -res : res;
  }
};
// @lc code=end
