/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  bool canConstruct(string s, string t) {
    vector<int> ch(26, 0);
    for (auto &c : s) ch[c - 'a']++;
    for (auto &c : t) ch[c - 'a']--;
    for (auto &i : ch)
      if (i > 0) return false;
    return true;
  }
};
// @lc code=end
