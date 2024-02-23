/*
 * @lc app=leetcode.cn id=1030 lang=cpp
 *
 * [1030] 距离顺序排列矩阵单元格
 */

#include "head.h"
using namespace std;
// @lc code=start

class Solution {
  int visit[150][150];
  int fx[4] = {1, 0, -1, 0};
  int fy[4] = {0, 1, 0, -1};

 public:
  vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
    queue<int> q, p;
    vector<vector<int>> res;
    int x, y;
    q.push(r0);
    q.push(c0);
    visit[r0][c0] = 1;
    while (q.size()) {
      while (q.size()) {
        x = q.front();
        q.pop();
        y = q.front();
        q.pop();
        res.push_back({x, y});
        if (x == R || y == C) {
          continue;
        }
        for (int i = 0; i < 4; i++) {
          int new_x = x + fx[i], new_y = y + fy[i];
          if (new_x >= 0 && new_x < R && new_y >= 0 && new_y < C &&
              !visit[new_x][new_y]++) {
            p.push(x + fx[i]);
            p.push(y + fy[i]);
          }
        }
      }
      q.swap(p);
    }
    return res;
  }
};
// @lc code=end
