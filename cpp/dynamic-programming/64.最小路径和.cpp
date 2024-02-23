/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  int minPathSum(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    bool flag = true;
    for (int i = n - 1; i >= 0; i--) {
      for (int j = m - 1; j >= 0; j--) {
        if (flag) {
          flag = false;
          continue;
        }
        auto &&a = (j + 1 >= m) ? (1 << 28) : grid[i][j + 1],
             &&b = (i + 1 >= n) ? (1 << 28) : grid[i + 1][j];
        auto&& self = grid[i][j];
        self = min(self + a, self + b);
      }
    }
    return grid[0][0];
  }
};
// @lc code=end
