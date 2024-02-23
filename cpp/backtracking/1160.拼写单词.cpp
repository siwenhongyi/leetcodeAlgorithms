/*
 * @lc app=leetcode.cn id=1160 lang=cpp
 *
 * [1160] 拼写单词
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  int countCharacters(vector<string> &words, string chars) {
    int res = 0;
    for (auto &i : words) {
      bool b = true;
      string t = chars;
      for (auto &j : i) {
        int index = t.find_first_of(j);
        if (index == t.npos) {
          b = false;
          break;
        } else
          t.erase(t.begin() + index);
      }
      if (b) res += i.size();
    }
    return res;
  }
};

// @lc code=end
