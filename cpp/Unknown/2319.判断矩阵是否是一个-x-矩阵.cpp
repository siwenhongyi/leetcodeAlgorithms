/*
 * @lc app=leetcode.cn id=2319 lang=cpp
 *
 * [2319] 判断矩阵是否是一个 X 矩阵
 */

#include "head.h"
using namespace std;

// @lc code=start
class Solution {
 public:
  bool checkXMatrix(vector<vector<int>>& grid) {
    if (!grid[0][0]) return false;
    int n = grid.size();
    for (int i = 0; i < n; i++) {
      int op = 2 - int(n % 2 && i == n / 2);
      if (n - count(grid[i].begin(), grid[i].end(), 0) != op) return false;
    }
    return true;
  }
};
// @lc code=end
