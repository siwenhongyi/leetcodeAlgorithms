/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II Medium (52.52%)
 */

#include "head.h"
using namespace std;

// @lc code=start
class Solution {
  bool searchMatrix_binarySearch(vector<vector<int>>& mat, int target) {
    int n = mat.size(), m = mat[0].size();
    int l, r, mid;
    for (int i = 0; i < n; i++) {
      if (mat[i][0] > target) return false;
      if (mat[i][m - 1] < target) continue;
      l = 0, r = m - 1;
      while (l <= r) {
        mid = (l + r) >> 1;
        if (mat[i][mid] == target) return true;
        if (mat[i][mid] > target)
          r = mid - 1;
        else
          l = mid + 1;
      }
    }
    return false;
  }
  bool searchMatrix_z(vector<vector<int>>& mat, int target) {
    int n = mat.size(), m = mat[0].size();
    int x = 0, y = m - 1;
    while (x < n && y >= 0) {
      auto& t = mat[x][y];
      if (t == target) return true;
      if (t > target)
        y--;
      else
        x++;
    }
    return false;
  }

 public:
  bool searchMatrix(vector<vector<int>>& mat, int target) {
    // return searchMatrix_binarySearch(mat, target);
    return searchMatrix_z(mat, target);
  }
};
// @lc code=end
