/*
* @lc app=leetcode.cn id=63 lang=cpp
*
* [63] 不同路径 II
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  int uniquePathsWithObstacles(vector<vector<int>>& obs) {
    if (obs[0][0] || obs.back().back()) return 0;
    int n = obs.size(), m = obs[0].size(), t;
    vector<vector<int>> res(n, vector<int>(m, 0));
    for (int i = 0; i < m && !obs[0][i]; i++) res[0][i] = 1;
    for (int i = 0; i < n && !obs[i][0]; i++) res[i][0] = 1;
    for (int i = 1; i < n; i++) {
      for (int j = 1; j < m; j++) {
        res[i][j] = obs[i][j] ? 0 : res[i - 1][j] + res[i][j - 1];
      }
    }
    return res.back().back();
  }
};
// @lc code=end

