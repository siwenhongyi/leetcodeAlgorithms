/*
 * @lc app=leetcode.cn id=1514 lang=cpp
 *
 * [1514] 概率最大的路径
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  double maxProbability(int n, vector<vector<int>>& edges,
                        vector<double>& succProb, int start, int end) {
    vector<bool> vi(n, false);
    vector<vector<pair<double, int>>> path(n, vector<pair<double, int>>());
    for (int i = 0; i < edges.size(); i++) {
      auto& e = edges[i];
      path[e[0]].push_back({succProb[i], e[1]});
      path[e[1]].push_back({succProb[i], e[0]});
    }
    priority_queue<pair<double, int>> pq;
    pq.push({1, start});
    while (!pq.empty()) {
      auto iter = pq.top();
      auto curProb = iter.first;
      auto cur = iter.second;
      pq.pop();
      if (vi[cur]) continue;
      vi[cur] = true;
      if (cur == end) return curProb;
      for (auto it : path[cur]) {
        auto nextProb = it.first;
        auto next = it.second;
        if (vi[next]) continue;
        pq.push({curProb * nextProb, next});
      }
    }
    return 0;
  }
};
// @lc code=end
