/*
 * @lc app=leetcode.cn id=766 lang=cpp
 *
 * [766] 托普利茨矩阵
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  bool isToeplitzMatrix(vector<vector<int>>& mat) {
    int n = mat.size(), m = mat[0].size();
    for (int i = 1; i < n; i++)
      for (int j = 1; j < m; j++)
        if (mat[i][j] != mat[i - 1][j - 1]) return false;
    return true;
  }
};
// @lc code=end
