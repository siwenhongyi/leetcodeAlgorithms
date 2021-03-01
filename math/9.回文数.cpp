/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */
#include "head.h"
// @lc code=start
class Solution {
 public:
  bool isPalindrome(int x) {
    if (x < 0) return false;
    string res = to_string(x);
    string ans = res;
    reverse(res.begin(), res.end());
    return res == ans;
  }
};
// @lc code=end
