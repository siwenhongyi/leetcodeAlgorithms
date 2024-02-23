/*
 * @lc app=leetcode.cn id=994 lang=cpp
 *
 * [994] 腐烂的橘子
 */

#include "head.h"
using namespace std;
// @lc code=start
typedef pair<int, int> pp;
int fx[] = {-1, 0, +1, 0}, fy[] = {0, +1, 0, -1};
class Solution {
 public:
  int orangesRotting(vector<vector<int>>& arr) {
    queue<pp> pos, t;
    int n = arr.size(), m = arr[0].size();
    int res = 0, cou = 0;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        if (arr[i][j] == 0)
          continue;
        else if (arr[i][j] == 1)
          cou++;
        else {
          pos.push({i, j});
          arr[i][j] = 0;
        }
    int pre, x, y, xx, yy;
    while (cou) {
      pre = cou;
      while (!pos.empty()) {
        auto qa = pos.front();
        pos.pop();
        x = qa.first, y = qa.second;
        for (int i = 0; i < 4; i++) {
          xx = x + fx[i], yy = y + fy[i];
          if (xx < 0 || xx >= n || yy < 0 || yy >= m ||
              arr[x + fx[i]][y + fy[i]] == 0)
            continue;
          else {
            arr[x + fx[i]][y + fy[i]] = 0;
            t.push({x + fx[i], y + fy[i]});
            cou--;
          }
        }
      }
      if (cou == pre) return -1;
      res++;
      pos.swap(t);
    }
    return res;
  }
};

// @lc code=end
