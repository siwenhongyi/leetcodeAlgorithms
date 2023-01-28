/*
 * @lc app=leetcode.cn id=2545 lang=cpp
 *
 * [2545] 根据第 K 场考试的分数排序
 */
#include "head.h"
// @lc code=start
class Solution {
  using uii = pair<int, int>;

 public:
  vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
    vector<uii> pri;
    vector<vector<int>> res;
    int n = score.size();
    for (int i = 0; i < n; i++) {
      auto&& it = score[i];
      pri.emplace_back(-it[k], i);
    }
    sort(pri.begin(), pri.end());
    for (auto& it : pri) {
      res.push_back(score[it.second]);
    }
    return res;
  }
};
// @lc code=end
