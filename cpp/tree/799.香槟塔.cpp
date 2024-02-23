/*
 * @lc app=leetcode.cn id=799 lang=cpp
 *
 * [799] 香槟塔
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  double champagneTower(int p, int x, int y) {
    vector<vector<double>> mat(x + 2);
    mat[0].resize(1, double(p) * 250);
    double t;
    for (int i = 0; i < x + 1; i++) {
      mat[i + 1].resize(i + 2, 0);
      for (int j = 0; j <= i; j++) {
        if (mat[i][j] <= 250) continue;
        t = mat[i][j] - 250;
        mat[i][j] = 250;
        mat[i + 1][j] += t / 2.0;
        mat[i + 1][j + 1] += t / 2.0;
      }
    }
    return mat[x][y] / 250.0;
  }
};
// @lc code=end
