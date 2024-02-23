/*
 * @lc app=leetcode.cn id=1332 lang=cpp
 *
 * [1332] 删除回文子序列
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  int removePalindromeSub(string s) {
    if (s.size() < 1) return 0;
    string t(s);
    reverse(t.begin(), t.end());
    if (s == t)
      return 1;
    else
      return 2;
  }
};
// @lc code=end
