/*
 * @lc app=leetcode.cn id=1631 lang=cpp
 *
 * [1631] 最小体力消耗路径
 */

#include "head.h"
using namespace std;
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
    int a = find(x), b = find(y);
    if (a == b) return;
    if (a > b) swap(a, b);
    parent[b] = a;
  }
  bool query(int x, int y) { return find(x) == find(y); }
};

class Solution {
 public:
  int minimumEffortPath(vector<vector<int>>& heights) {
    int n = heights.size(), m = heights[0].size();
    int index;
    vector<tuple<int, int, int>> edge;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) {
        index = i * m + j;
        if (i)
          edge.emplace_back(index, index - m,
                            abs(heights[i][j] - heights[i - 1][j]));
        if (j)
          edge.emplace_back(index, index - 1,
                            abs(heights[i][j] - heights[i][j - 1]));
      }
    sort(edge.begin(), edge.end(), [](const auto& s, const auto& t) {
      auto&& [a, b, c] = s;
      auto&& [x, y, z] = t;
      return c < z;
    });
    U u(m * n);
    int res = 0;
    for (const auto& [x, y, z] : edge) {
      u.Union(x, y);
      if (u.query(0, m * n - 1)) {
        res = z;
        break;
      }
    }
    return res;
  }
};
// @lc code=end
