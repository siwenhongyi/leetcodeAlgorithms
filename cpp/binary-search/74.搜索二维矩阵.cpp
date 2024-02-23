/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n = matrix.size(), m = matrix[0].size();
    int left = 0, right = n * m;
    while (left < right) {
      auto&& mid = left + (right - left) / 2;
      auto&& t = matrix[mid / m][mid % m];
      if (t == target)
        return true;
      else if (t > target)
        right = mid;
      else
        left = mid + 1;
    }
    return false;
  }
};
// @lc code=end
