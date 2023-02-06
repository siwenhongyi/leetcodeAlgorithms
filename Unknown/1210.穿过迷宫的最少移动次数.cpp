/*
 * @lc app=leetcode.cn id=1210 lang=cpp
 *
 * [1210] 穿过迷宫的最少移动次数
 */

#include "head.h"
using namespace std;

// @lc code=start
class Solution {
  // 头尾坐标以及运行长短
  using ti = tuple<int, int, int, int, int>;
  // 头尾坐标
  using node = tuple<int, int, int, int>;
  // 右 下 顺转 逆转 左 上
  // 头坐标不同移动变化方式
  static constexpr array fxh{0, 1, 1, -1}, fyh{1, 0, -1, 1};
  // 尾坐标不同的编号方式
  static constexpr array fxt{0, 1, 0, 0}, fyt{1, 0, 0, 0};

 public:
  int minimumMoves(vector<vector<int>> &g) {
    int res = -1, n = g.size();
    set<node> v;
    queue<ti> q;
    q.push({0, 1, 0, 0, 0});
    v.insert({0, 1, 0, 0});
    bool row, col;
    while (q.size()) {
      auto [xh, yh, xt, yt, length] = q.front();
      q.pop();
      row = xh == xt && yh == yt + 1, col = xh == xt + 1 && yh == yt;
      if (xh == n - 1 && yh == n - 1 && xt == n - 1 && yt == n - 2) {
        res = length;
        break;
      }
      for (int i = 0; i < 4; i++) {
        // 顺时针 但是不是横着的
        if (i == 2 && !row) continue;
        // 逆时针 不是竖着的
        if (i == 3 && !col) continue;
        auto &&new_xh = xh + fxh[i], &&new_yh = yh + fyh[i];
        if (new_xh < 0 || new_xh >= n || new_yh < 0 || new_yh >= n) continue;
        if (g[new_xh][new_yh]) continue;
        auto &&new_xt = xt + fxt[i], &&new_yt = yt + fyt[i];
        if (new_xt < 0 || new_xt >= n || new_yt < 0 || new_yt >= n) continue;
        if (g[new_xt][new_yt]) continue;
        if (i == 2 && (g[new_xh][new_yh + 1])) continue;
        if (i == 3 && g[new_xh + 1][new_yh]) continue;
        if (v.count({new_xh, new_yh, new_xt, new_yt})) continue;
        v.insert({new_xh, new_yh, new_xt, new_yt});
        q.push({new_xh, new_yh, new_xt, new_yt, length + 1});
      }
    }
    return res;
  }
};
// @lc code=end
