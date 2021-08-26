/*
 * @lc app=leetcode.cn id=787 lang=cpp
 *
 * [787] K 站中转内最便宜的航班
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                        int k) {
    unordered_map<int, unordered_map<int, int>> edges;
    unordered_map<int, int> seen;
    for (auto& flight : flights) {
      edges[flight[0]][flight[1]] = flight[2];
    }
    queue<pair<int, int>> q;
    q.emplace(src, 0);
    seen[src] = 0;
    int res = (1 << 30);
    k++;
    while (k--) {
      int cnt = q.size();
      while (cnt--) {
        auto [d, p] = q.front();
        q.pop();
        for (auto& [t, v] : edges[d]) {
          if (seen.find(t) != seen.end() && seen[t] < (p + v)) {
            continue;
          } else if (t == dst) {
            res = min(res, p + v);
          } else if (p + v < res) {
            q.emplace(t, p + v);
            seen[t] = p + v;
          }
        }
      }
    }
    return res == (1 << 30) ? -1 : res;
  }
};
// @lc code=end
