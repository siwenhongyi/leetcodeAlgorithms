/*
 * @lc app=leetcode.cn id=342 lang=cpp
 *
 * [342] 4的幂
 */
#include "head.h"
// @lc code=start
class Solution {
 public:
  bool isPowerOfFour(int n) {
    if (n <= 0) return false;
    while (n >= 4) {
      if ((n & (n - 1)) != 0) return false;
      n /= 4;
    }
    return n == 1;
  }
};
// @lc code=end
