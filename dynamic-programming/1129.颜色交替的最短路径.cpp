/*
 * @lc app=leetcode.cn id=1129 lang=cpp
 *
 * [1129] 颜色交替的最短路径
 */

#include "head.h"
using namespace std;

// @lc code=start
class Solution {
  using pii = pair<int, int>;

 public:
  vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges,
                                       vector<vector<int>>& blueEdges) {
    vector<vector<vector<int>>> e(2, vector<vector<int>>(n));
    for (auto& it : redEdges) {
      e[0][it[0]].push_back(it[1]);
    }
    for (auto& it : blueEdges) {
      e[1][it[0]].push_back(it[1]);
    }
    static const int mlength = 1000;
    vector<priority_queue<pii, vector<pii>, greater<pii>>> tq(2);
    vector<map<int, int>> v(2);
    vector<vector<int>> ans(2, vector<int>(n, mlength));
    tq[0].push({0, 0});
    tq[1].push({0, 0});
    int index, index_size = mlength;
    bool flag = false;
    int check = 0;
    while (!flag) {
      for (int i = 0; i < 2; i++) {
        if (tq[i].empty()) continue;
        auto [index_size, index] = tq[i].top();
        auto&& next_color_index = (i + 1) % 2;
        tq[i].pop();
        // 更新ans
        ans[i][index] = min(index_size, ans[i][index]);
        // 寻找存在不同路径下一步切小于原有大小的
        if (v[i][index]++ == 0) {
          for (auto& j : e[next_color_index][index]) {
            tq[next_color_index].push({index_size + 1, j});
          }
        }
      }
      flag = tq[0].empty() && tq[1].empty();
      // cout<<tq[0].size()<<' '<<tq[1].size()<<'\n';
      // if(check++==100)break;
    }
    vector<int> res(n, -1);
    for (int i = 0; i < n; i++) {
      if (ans[0][i] == mlength && ans[1][i] == mlength) continue;
      res[i] = min(ans[0][i], ans[1][i]);
    }
    return res;
  }
};
// @lc code=end
