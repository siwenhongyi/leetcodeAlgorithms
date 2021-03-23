/*
 * @lc app=leetcode.cn id=73 lang=cpp
 *
 * [73] 矩阵置零
 */
#include "head.h"
// @lc code=start
class Solution {
 public:
  void setZeroes(vector<vector<int>>& matrix) {
    int n = matrix.size(), m = matrix[0].size();
    bool flag = false;
    for (int i = 0; i < n; ++i) {
      if (matrix[i][0] == 0) flag = true;
      for (int j = 1; j < m; ++j) {
        if (!matrix[i][j]) matrix[i][0] = matrix[0][j] = 0;
      }
    }
    for (int i = n - 1; i >= 0; --i) {
      for (int j = 1; j < m; ++j) {
        if (!matrix[i][0] || !matrix[0][j]) matrix[i][j] = 0;
      }
      if (flag) matrix[i][0] = 0;
    }
    return;
  }
};
// @lc code=end
