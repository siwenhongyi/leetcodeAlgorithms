/*
 * @lc app=leetcode.cn id=68 lang=cpp
 *
 * [68] 文本左右对齐
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 private:
  string get_temp_ans(vector<string>& words, int l, int r, const string& s) {
    string res = words[l++];
    while (l < r) {
      res += s + words[l++];
    }
    return res;
  }

 public:
  vector<string> fullJustify(vector<string>& words, int maxWidth) {
    int index = 0, n = words.size();
    vector<string> res;
    int t, length;
    while (index < n) {
      t = index, length = 0;
      while (index < n &&
             length + words[index].size() + index - t <= maxWidth) {
        length += words[index++].size();
      }
      if (index == n) {
        auto&& s = get_temp_ans(words, t, index, " ");
        res.emplace_back(s + string(maxWidth - s.size(), ' '));
        return res;
      }
      auto &&cnt = index - t, &&space_nums = maxWidth - length;
      if (cnt == 1) {
        res.emplace_back(words[t] + string(space_nums, ' '));
        continue;
      }
      auto &&space_avg = space_nums / (cnt - 1),
           &&over_space_nums = space_nums % (cnt - 1);
      auto &&s1 = get_temp_ans(words, t, t + over_space_nums + 1,
                               string(space_avg + 1, ' ')),
           &&s2 = get_temp_ans(words, t + over_space_nums + 1, index,
                               string(space_avg, ' '));
      res.emplace_back(s1 + string(space_avg, ' ') + s2);
    }
    return res;
  }
};
// @lc code=end
