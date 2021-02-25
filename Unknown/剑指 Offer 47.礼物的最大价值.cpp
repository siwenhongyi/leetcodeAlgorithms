/*
 * @lc app=leetcode.cn id=剑指 Offer 47 lang=cpp
 *
 * [剑指 Offer 47] 礼物的最大价值
 */

#include "head.h"
using namespace std;
// @lc code=start
const int fx[] = {0, 1};
const int fy[] = {1, 0};

class Solution {
 public:
  int maxValue(vector<vector<int>>& grid) {
    int res = 0;
    if (grid.empty()) return res;
    int n = grid.size(), m = grid[0].size();
    int t[] = {0, 0};
    for (int i = n - 1; i >= 0; i--) {
      for (int j = m - 1; j >= 0; j--) {
        t[0] = t[1] = 0;
        for (int k = 0; k < 2; k++)
          if (i + fx[k] < n && j + fy[k] < m) t[k] = grid[i + fx[k]][j + fy[k]];
        grid[i][j] += max(t[0], t[1]);
      }
    }
    return grid[0][0];
  }
};

// @lc code=end
