/*
 * @lc app=leetcode.cn id=1380 lang=cpp
 *
 * [1380] 矩阵中的幸运数
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  vector<int> luckyNumbers(vector<vector<int>>& mat) {
    map<int, int> pos, book;
    vector<int> res;
    int n = mat.size(), m = mat[0].size();
    int t;
    for (int i = 0; i < n; i++) {
      int t = mat[i][0];
      pos[0] = max(pos[0], t);
      pair<int, int> te{t, 0};
      for (int j = 1; j < m; j++) {
        if (mat[i][j] < t) {
          t = mat[i][j];
          te = make_pair(t, j);
        }
        pos[j] = max(pos[j], mat[i][j]);
      }
      book[te.first] = te.second;
    }
    for (auto& it : book) {
      if (it.first >= pos[it.second]) res.push_back(it.first);
    }
    return res;
  }
};
// @lc code=end
