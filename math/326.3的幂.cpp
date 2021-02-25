/*
 * @lc app=leetcode.cn id=326 lang=cpp
 *
 * [326] 3的幂
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  bool isPowerOfThree(int n) {
    int m = 1162261467;
    return n > 0 && m % n == 0;
  }
};
// @lc code=end
