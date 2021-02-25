/*
 * @lc app=leetcode.cn id=1165 lang=cpp
 *
 * [1165] 单行键盘
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  int calculateTime(string keyboard, string word) {
    unordered_map<char, int> pos;
    for (int i = 0; i < keyboard.size(); i++) pos[keyboard[i]] = i;
    int res = 0;
    for (unsigned int i = 1; i < word.size(); i++)
      res += abs(pos[word[i]] - pos[word[i - 1]]);
    res += pos[word.front()];
    return res;
  }
};

// @lc code=end
