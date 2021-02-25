/*
 * @lc app=leetcode.cn id=1337 lang=cpp
 *
 * [1337] 矩阵中战斗力最弱的 K 行
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
    vector<int> res;
    vector<vector<int>> ans;
    int n = mat.size(), i, j, m;
    for (i = 0; i < n; i++) {
      j = 0;
      m = mat[i].size();
      while (j < m && mat[i][j] == 1) j++;
      ans.push_back({j, m - j, i});
    }
    sort(ans.begin(), ans.end(),
         [](const vector<int>& s, const vector<int>& t) {
           if (s[0] != t[0]) return s[0] < t[0];
           return s[2] < t[2];
         });
    for (i = 0; i < k; i++) res.push_back(ans[i][2]);
    return res;
  }
};
// @lc code=end
