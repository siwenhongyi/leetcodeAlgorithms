/*
 * @lc app=leetcode.cn id=2546 lang=cpp
 *
 * [2546] 执行逐位运算使字符串相等
 */
#include "head.h"
// @lc code=start
class Solution {
 public:
  bool makeStringsEqual(string s, string target) {
    return (s.find('1') == string::npos) == (target.find('1') == string::npos);
  }
};
// @lc code=end
