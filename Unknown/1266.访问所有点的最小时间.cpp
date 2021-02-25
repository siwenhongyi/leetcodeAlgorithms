/*
 * @lc app=leetcode.cn id=1266 lang=cpp
 *
 * [1266] 访问所有点的最小时间
 */
#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  int minTimeToVisitAllPoints(vector<vector<int>> &pos) {
    if (pos.empty()) return 0;
    int res = 0, n = pos.size();
    int x = pos[0][0], y = pos[0][1];
    int move_x, move_y;
    for (int i = 1; i < n; i++) {
      move_x = abs(pos[i][0] - x), move_y = abs(pos[i][1] - y);
      res += min(move_x, move_y) + abs(move_x - move_y);
      x = pos[i][0], y = pos[i][1];
    }
    return res;
  }
};
// @lc code=end
