/*
 * @lc app=leetcode.cn id=1637 lang=cpp
 *
 * [1637] 两点之间不包含任何点的最宽垂直面积
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  int maxWidthOfVerticalArea(vector<vector<int>>& points) {
    if (points.empty()) return 0;
    sort(points.begin(), points.end());
    int res = 0;
    for (int i = 1; i < points.size(); i++)
      res = max(res, points[i][0] - points[i - 1][0]);
    return res;
  }
};

// @lc code=end
