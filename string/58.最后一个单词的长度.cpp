/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  int lengthOfLastWord(string s) {
    if (s.empty()) return 0;
    int index = s.size() - 1, n = s.size();
    while (index >= 0 && s[index] == ' ') index--;
    if (index < 0) return 0;
    int i = index;
    while (i >= 0 && s[i] != ' ') i--;
    return index - i;
  }
};
// @lc code=end
