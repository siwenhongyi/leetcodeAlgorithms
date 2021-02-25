/*
 * @lc app=leetcode.cn id=345 lang=cpp
 *
 * [345] 反转字符串中的元音字母
 */

#include "head.h"
using namespace std;
// @lc code=start

class Solution {
 public:
  string reverseVowels(string s) {
    if (s.size() <= 1) return s;
    string t = "aoeiuAOEIU";
    map<char, int> book;
    for (auto i : t) book[i]++;
    auto it = s.begin(), iter = s.end() - 1;
    while (it < iter) {
      while (it < iter && !book[*it]) it++;
      while (it < iter && !book[*iter]) iter--;
      swap(*it, *iter);
      it++;
      iter--;
    }
    return s;
  }
};
// @lc code=end
