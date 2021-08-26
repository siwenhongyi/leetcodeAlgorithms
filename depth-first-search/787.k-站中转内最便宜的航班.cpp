/*
 * @lc app=leetcode.cn id=787 lang=cpp
 *
 * [787] K 站中转内最便宜的航班
 */

#include "head.h"
using namespace std;
// @lc code=start
// this code timeout now
class Solution {
 private:
  int st, en, res;
  bool flag;
  vector<bool> visit;
  vector<vector<int>> edge;

 public:
  void dfs(int index, int step, int len) {
    if (step < 0 || len > res) return;
    if (index == en) {
      flag = true;
      if (len < res) res = len;
      return;
    }
    visit[index] = false;
    for (int i = 0; i < edge[index].size(); i += 2) {
      if (visit[edge[index][i]])
        dfs(edge[index][i], step - 1, len + edge[index][i + 1]);
    }
    visit[index] = true;
  }
  int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                        int k) {
    st = src;
    en = dst;
    res = (1 << 31) - 1;
    flag = false;
    visit.resize(n, true);
    edge.resize(n);
    for (auto& i : flights) {
      edge[i[0]].push_back(i[1]);
      edge[i[0]].push_back(i[2]);
    }
    dfs(st, k + 1, 0);
    if (flag) return res;
    return -1;
  }
};

// @lc code=end
