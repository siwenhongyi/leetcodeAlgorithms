/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  bool wordBreak(string s, vector<string>& Dict) {
    int n = s.size();
    vector<bool> res(n + 1, false);
    unordered_set<string> dict;
    unordered_map<int, string> pos;
    for (auto& it : Dict) dict.insert(it);
    res[0] = true;
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < i; j++) {
        if (res[j]) {
          auto& ch = pos[j * n + i - j];
          if (ch.empty()) ch = s.substr(j, i - j);
          res[i] = dict.count(ch);
        }
        if (res[i]) break;
      }
    }
    return res.back();
  }
};
// @lc code=end
