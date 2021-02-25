/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  vector<int> spiralOrder(vector<vector<int>>& mat) {
    if (mat.empty()) return {};
    vector<int> res;
    int t, l, i;
    t = l = 0;
    int d = mat.size() - 1;
    int r = mat[0].size() - 1;
    while (true) {
      for (i = l; i <= r; i++) res.push_back(mat[t][i]);
      if (++t > d) break;
      for (i = t; i <= d; i++) res.push_back(mat[i][r]);
      if (--r < l) break;
      for (i = r; i >= l; i--) res.push_back(mat[d][i]);
      if (--d < t) break;
      for (i = d; i >= t; i--) res.push_back(mat[i][l]);
      if (++l > r) break;
    }
    return res;
  }
};
// @lc code=end
