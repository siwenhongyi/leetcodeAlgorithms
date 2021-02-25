/*
 * @lc app=leetcode.cn id=1329 lang=cpp
 *
 * [1329] 将矩阵按对角线排序
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
    int n = mat.size(), m = mat[0].size();
    int i, j, k, q;
    if (n <= 1) return mat;
    vector<int> t;
    for (j = m - 1; j >= 0; j--) {
      i = 0, k = j;
      while (k < m && i < n) t.push_back(mat[i++][k++]);
      sort(t.begin(), t.end());
      i = q = 0, k = j;
      while (q < t.size()) mat[i++][k++] = t[q++];
      t.clear();
    }
    for (i = 1; i < n; i++) {
      j = 0, k = i;
      while (k < n && j < m) t.push_back(mat[k++][j++]);
      sort(t.begin(), t.end());
      j = q = 0, k = i;
      while (q < t.size()) mat[k++][j++] = t[q++];
      t.clear();
    }
    return mat;
  }
};
// @lc code=end
