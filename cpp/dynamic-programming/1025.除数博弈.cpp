/*
 * @lc app=leetcode.cn id=1025 lang=cpp
 *
 * [1025] 除数博弈
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  bool divisorGame(int n) { return !(n & 1); }
};
// @lc code=end
