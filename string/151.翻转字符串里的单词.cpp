/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 翻转字符串里的单词
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  string reverseWords(string s) {
    if (s.empty()) return s;
    reverse(s.begin(), s.end());
    int i, j, n, index = 0;
    n = s.size();
    i = 0;
    while (i < n && s[i] == ' ') i++;
    if (i == n) return "";
    while (i < n) {
      while (i < n && s[i] == ' ') i++;
      j = i;
      while (j < n && s[j] != ' ') j++;
      reverse(s.begin() + i, s.begin() + j);
      while (i < j) s[index++] = s[i++];
      s[index++] = s[i++];
    }

    s.resize(index - 1);
    while (s.back() == ' ') s.pop_back();
    return s;
  }
};

// @lc code=end
