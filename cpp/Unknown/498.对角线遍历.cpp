/*
 * @lc app=leetcode.cn id=498 lang=cpp
 *
 * [498] 对角线遍历
 */
#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
    int n = mat.size(), m = mat[0].size();
    int i, j, k;
    i = j = 0;
    vector res(0, 0);
    while (i < n && j < m) {
      while (i >= 0 && j < m) res.emplace_back(mat[i--][j++]);
      i++, j--;
      if (i < 0 || i == n || j < 0 || j == m) break;
      if (i || j == m - 1)
        i++;
      else
        j++;
      while (j >= 0 && i < n) res.emplace_back(mat[i++][j--]);
      i--, j++;
      if (j || i == n - 1)
        j++;
      else
        i++;
    }
    return res;
  }
};
// @lc code=end
