/*
 * @lc app=leetcode.cn id=778 lang=cpp
 *
 * [778] 水位上升的泳池中游泳
 */
#include "head.h"
// @lc code=start
class U {
 private:
  vector<int> parent;

 public:
  U(int size_) : parent(size_) { iota(parent.begin(), parent.end(), 0); }
  ~U() {}

 public:
  int find(int index) {
    return index == parent[index] ? index : parent[index] = find(parent[index]);
  }
  void Union(int x, int y) {
    int xx = find(x), yy = find(y);
    if (xx == yy) return;
    if (xx > yy) swap(xx, yy);
    parent[yy] = xx;
  }
  bool query(int x, int y) { return find(x) == find(y); }
};
class Solution {
 public:
  int swimInWater(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    int index;
    vector<tuple<int, int, int>> edge;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        index = i * m + j;
        if (i != n - 1)
          edge.emplace_back(index, index + m, max(grid[i][j], grid[i + 1][j]));
        if (j != m - 1)
          edge.emplace_back(index, index + 1, max(grid[i][j], grid[i][j + 1]));
      }
    }
    sort(edge.begin(), edge.end(), [](const auto& s, const auto& t) {
      auto&& [a, b, c] = s;
      auto&& [x, y, z] = t;
      return c < z;
    });
    U u(m * n);
    for (auto& [a, b, c] : edge) {
      u.Union(a, b);
      if (u.query(0, m * n - 1)) return c;
    }
    return 0;
  }
};
// @lc code=end
