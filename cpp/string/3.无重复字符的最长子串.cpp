/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */
#include "head.h"
// @lc code=start
class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    if (s.size() < 2) return s.size();
    int res = 0, n = s.size();
    unordered_map<char, int> pos;
    int i, j;
    i = j = 0;
    while (j < n) {
      if (pos[s[j]]++) {
        while (pos[s[j]] == 2) pos[s[i++]]--;
      }
      res = max(j - i + 1, res);
      j++;
    }
    return res;
  }
};
// @lc code=end
