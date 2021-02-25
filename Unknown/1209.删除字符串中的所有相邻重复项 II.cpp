/*
 * @lc app=leetcode.cn id=1209 lang=cpp
 *
 * [1209] 删除字符串中的所有相邻重复项 II
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  string removeDuplicates(string s, int k) {
    if (s.empty()) return s;
    int i, j, n = s.size();
    bool b = true;
    i = j = 0;
    while (b) {
      b = false;
      i = j = 0;
      while (i < n) {
        while (j < n && s[j] == s[i]) j++;
        if (j - i >= k) {
          s.erase(s.begin() + i, s.begin() + i + k);
          b = true;
        }
        i = j;
      }
    }
    return s;
  }
};

// @lc code=end
