/*
 * @lc app=leetcode.cn id=1624 lang=cpp
 *
 * [1624] 两个相同字符之间的最长子字符串
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  int maxLengthBetweenEqualCharacters(string s) {
    int res = -1;
    vector<int> charFirstIndex(26, -1);
    size_t index = 0, n = s.size();
    while (index < n) {
      size_t charIndex = s[index] - 'a';
      if (charFirstIndex[charIndex] == -1) {
        charFirstIndex[charIndex] = index;
      } else
        res = max(res, (int)index - charFirstIndex[charIndex] - 1);

      index++;
    }
    return res;
  }
};
// @lc code=end
