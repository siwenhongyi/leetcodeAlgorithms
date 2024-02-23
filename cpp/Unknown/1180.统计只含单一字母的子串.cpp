/*
 * @lc app=leetcode.cn id=1180 lang=cpp
 *
 * [1180] 统计只含单一字母的子串
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  int countLetters(string s) {
    if (s.size() < 2) return s.size();
    int i, j, res, n = s.size();
    char c;
    i = j = res = 0;
    while (j < n) {
      c = s[j];
      i = j;
      while (j < n && s[j] == c) j++;
      res += (j - i) + ((j - i) * (j - i - 1)) / 2;
    }
    return res;
  }
};

// @lc code=end
