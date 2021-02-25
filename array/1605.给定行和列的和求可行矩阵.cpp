/*
 * @lc app=leetcode.cn id=1605 lang=cpp
 *
 * [1605] 给定行和列的和求可行矩阵
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
    int n = rowSum.size(), m = colSum.size();
    vector<vector<int>> res(n, vector<int>(m, 0));
    vector<int> col(m, 0);
    for (int i = 0; i < n; i++) {
      int row = rowSum[i];
      for (int j = 0; j < m && row > 0; j++) {
        if (row >= colSum[j]) {
          res[i][j] = colSum[j];
          row -= colSum[j];
          colSum[j] = 0;
        } else {
          colSum[j] -= row;
          res[i][j] = row;
          row = 0;
          break;
        }
      }
    }
    return res;
  }
};

// @lc code=end
