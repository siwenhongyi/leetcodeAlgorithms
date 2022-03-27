/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  vector<vector<int>> merge(vector<vector<int>>& arrs) {
    int n = arrs.size();
    if (n <= 1) return arrs;
    sort(arrs.begin(), arrs.end(), [](const auto& s, const auto& t) {
      if (s.front() != t.front()) return s.front() < t.front();
      return s.back() < t.back();
    });
    vector<vector<int>> res;
    int a = arrs[0][0], b = arrs[0][1];
    for (int i = 1; i < n; i++) {
      auto &&bg = arrs[i].front(), &&en = arrs[i].back();
      if (bg > b) {
        res.push_back({a, b});
        a = bg, b = en;
      } else {
        b = max(b, en);
      }
    }
    res.push_back({a, b});
    return res;
  }
};
// @lc code=end
