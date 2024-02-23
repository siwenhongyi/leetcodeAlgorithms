/*
 * @lc app=leetcode.cn id=85 lang=cpp
 *
 * [85] 最大矩形
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 private:
 public:
  int maximalRectangle(vector<vector<char>>& matrix) {
    if (matrix.empty()) return 0;
    int n = matrix.size(), m = matrix[0].size();
    if (!m) return 0;
    vector<vector<int>> left(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
      int one = 0;
      for (int j = 0; j < m; j++) {
        one = matrix[i][j] == '1' ? one + 1 : 0;
        left[i][j] = one;
      }
    }
    int res = 0, width, area;
    for (int i = n - 1; i >= 0; i--) {
      for (int j = 0; j < m; j++) {
        if (matrix[i][j] == '0') continue;
        area = width = left[i][j];
        for (int k = i - 1; k >= 0; k--) {
          width = min(width, left[k][j]);
          if (width == 0) break;
          area = max(area, width * (i - k + 1));
          //   { cout << i << ' ' << j << ' ' << k << ' ' << area << ' '; }
          //   res = max(res, area);
        }
        res = max(res, area);
      }
    }
    return res;
  }
};
// @lc code=end
