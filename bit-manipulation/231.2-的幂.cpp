/*
 * @lc app=leetcode.cn id=231 lang=cpp
 *
 * [231] 2的幂
 */
#include "head.h"
// @lc code=start
class Solution {
 public:
  bool isPowerOfTwo(int n) {
    if (n <= 0 || (n & (n - 1)) != 0) return false;
    return true;
  }
};
// @lc code=end
