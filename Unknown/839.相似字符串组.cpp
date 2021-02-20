/*
 * @lc app=leetcode.cn id=839 lang=cpp
 *
 * [839] 相似字符串组
 */
#include "head.h"
// @lc code=start
class Solution {
 public:
  int numSimilarGroups(vector<string>& strs) {
    unordered_set<string> pos;
    for (auto& it : strs) {
      sort(it.begin(), it.end());
      pos.insert(it);
    }
    return pos.size();
  }
};
// @lc code=end
