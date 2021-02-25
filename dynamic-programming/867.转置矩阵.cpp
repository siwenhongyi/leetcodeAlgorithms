/*
 * @lc app=leetcode.cn id=867 lang=cpp
 *
 * [867] 转置矩阵
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  vector<vector<int>> transpose(vector<vector<int>>& mat) {
    int n = mat.size(), m = mat[0].size();
    vector<vector<int>> res(m, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        res[j][i] = mat[i][j];
      }
    }
    return res;
  }
};
// @lc code=end
