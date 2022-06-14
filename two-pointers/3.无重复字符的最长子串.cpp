/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */
#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    int res = 0, n = s.length();
    unordered_map<int, int> cnt;
    int i = 0, j = 0;
    while (j < n) {
      if (cnt[s[j]]) {
        while (i < j && s[i] != s[j]) cnt[s[i++]]--;
        cnt[s[i++]]--;
      }
      res = max(res, j - i + 1);
      cnt[s[j++]]++;
    }
    return res;
  }
};
// @lc code=end
