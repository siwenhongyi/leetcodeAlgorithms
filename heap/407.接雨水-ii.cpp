/*
 * @lc app=leetcode.cn id=407 lang=cpp
 *
 * [407] 接雨水 II
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
  using tpp = tuple<int, int, int>;
  static constexpr array fx{-1, 0, 1, 0};
  static constexpr array fy{0, 1, 0, -1};
  struct cmp {
    bool operator()(const tpp& s, const tpp& t) {
      auto&& [x0, y0, h0] = s;
      auto&& [x1, y1, h1] = t;
      return h0 > h1;
    }
  };

 public:
  int trapRainWater(vector<vector<int>>& heightMap) {
    int n = heightMap.size(), m = heightMap[0].size();
    priority_queue<tpp, vector<tpp>, cmp> q;
    unordered_set visited({0});
    for (int i = 0; i < n; i++) {
      q.push(tpp(i, 0, heightMap[i][0]));
      q.push(tpp(i, m - 1, heightMap[i][m - 1]));
      visited.insert(i * m);
      visited.insert(i * m + m - 1);
    }
    for (int i = 1; i < m - 1; i++) {
      q.push(tpp(0, i, heightMap[0][i]));
      q.push(tpp(n - 1, i, heightMap[n - 1][i]));
      visited.insert(i);
      visited.insert((n - 1) * m + i);
    }
    int res = 0;
    while (q.size()) {
      auto qa = q.top();
      q.pop();
      auto&& [x, y, h] = qa;
      for (int i = 0; i < 4; i++) {
        auto &&new_x = x + fx[i], &&new_y = y + fy[i];
        if (new_x < 0 || new_x >= n || new_y < 0 || new_y >= m) continue;
        if (visited.count(new_x * m + new_y)) continue;
        auto&& new_h = heightMap[new_x][new_y];
        if (new_h < h) res += h - new_h;
        q.push(tpp(new_x, new_y, max(h, new_h)));
        visited.insert(new_x * m + new_y);
      }
    }
    return res;
  }
};
// @lc code=end

int main() {
  /*
   * any test cases
   */
  Solution s;
  /*
  [[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]]
  */
  vector<vector<int>> heightMap = {
      {1, 4, 3, 1, 3, 2},
      {3, 2, 1, 3, 2, 4},
      {2, 3, 3, 2, 3, 1},
  };
  cout << s.trapRainWater(heightMap) << endl;
  /*
    [[3,3,3,3,3],[3,2,2,2,3],[3,2,1,2,3],[3,2,2,2,3],[3,3,3,3,3]]
  */
  heightMap = {
      {3, 3, 3, 3, 3}, {3, 2, 2, 2, 3}, {3, 2, 1, 2, 3},
      {3, 2, 2, 2, 3}, {3, 3, 3, 3, 3},
  };
  cout << s.trapRainWater(heightMap) << endl;
  return 0;
}
