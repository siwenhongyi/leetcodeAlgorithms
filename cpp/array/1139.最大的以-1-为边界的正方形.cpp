/*
 * @lc app=leetcode.cn id=1139 lang=cpp
 *
 * [1139] 最大的以 1 为边界的正方形 Medium (49.52%)
 */

#include "head.h"
using namespace std;

// @lc code=start
class Solution {
 public:
  int largest1BorderedSquare(vector<vector<int>> &g) {
    int n = g.size(), m = g[0].size();
    vector<vector<int>> row(n, vector<int>(m + 1, 0));
    // 行前缀和  第i行前j个和
    for (int i = 0; i < n; i++)
      for (int j = 1; j <= m; j++) row[i][j] = row[i][j - 1] + g[i][j - 1];
    vector<vector<int>> col(m, vector<int>(n + 1, 0));
    // 列前缀和 第j列 前i行和
    for (int j = 0; j < m; j++)
      for (int i = 1; i <= n; i++) col[j][i] = col[j][i - 1] + g[i - 1][j];
    // 遍历 左上角/右上角坐标x，y以及边长l
    int x, y, l, res = 0;
    for (x = 0; x < n; x++) {
      for (y = 0; y < m; y++) {
        if (!g[x][y]) continue;
        //[x,y] 为左上角
        for (l = 0; x + l < n && y + l < m; l++) {
          // 计算四条边前缀和
          auto &&a = row[x][y + l + 1] - row[x][y],
               &&b = row[x + l][y + l + 1] - row[x + l][y],
               &&c = col[y][x + l + 1] - col[y][x],
               &&d = col[y + l][x + l + 1] - col[y + l][x];
          if (a != l + 1 || b != l + 1 || c != l + 1 || d != l + 1) break;
          res = max(res, l + 1);
        }
        // [x,y]为右上角
        for (l = 1; x + l < n && y - l >= 0; l++) {
          auto &&a = row[x][y + 1] - row[x][y - l],
               &&b = row[x + l][y + 1] - row[x + l][y - l],
               &&c = col[y][x + l + 1] - col[y][x],
               &&d = col[y - l][x + l + 1] - col[y - l][x];
          if (a != l + 1 || b != l + 1 || c != l + 1 || d != l + 1) continue;
          res = max(res, l + 1);
        }
      }
    }
    return res * res;
  }
};
// @lc code=end
