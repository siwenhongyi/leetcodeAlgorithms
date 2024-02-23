/*
 * @lc app=leetcode.cn id=541 lang=cpp
 *
 * [541] 反转字符串 II
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  string reverseStr(string s, int k) {
    int n = s.size();
    size_t index = 0, rev_end;
    size_t left, right;
    while (index < n) {
      rev_end = index + k;
      if (rev_end >= n) rev_end = n;
      left = index, right = rev_end - 1;
      while (left < right) swap(s[left++], s[right--]);
      index = rev_end + k;
    }
    return s;
  }
};
// @lc code=end
