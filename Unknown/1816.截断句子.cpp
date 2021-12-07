/*
 * @lc app=leetcode.cn id=1816 lang=cpp
 *
 * [1816] 截断句子
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  string truncateSentence(string s, int k) {
    int index = 0, n = s.size();
    while (index < n && k--) {
      while (index < n && s[index++] != ' ')
        ;
    }
    return index == n ? s : s.substr(0, index - 1);
  }
};
// @lc code=end
