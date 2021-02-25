/*
 * @lc app=leetcode.cn id=389 lang=cpp
 *
 * [389] 找不同
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  char findTheDifference(string s, string t) {
    vector<int> pos(26, 0), v(26, 0);
    for (auto &ch : s) pos[ch - 'a']++;
    for (auto &ch : t) v[ch - 'a']++;
    for (int i = 0; i < 26; i++)
      if (pos[i] != v[i]) return 'a' + i;
    return t[0];
  }
};
// @lc code=end
