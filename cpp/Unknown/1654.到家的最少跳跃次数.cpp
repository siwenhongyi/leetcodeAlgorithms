/*
 * @lc app=leetcode.cn id=1654 lang=cpp
 *
 * [1654] 到家的最少跳跃次数
 */
#include "head.h"
// @lc code=start
class Solution {
 public:
  int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
    int g = __gcd(a, b);
    if ((x % g) != 0) {
      return -1;
    }

    int vis[6001], ban[2001];
    memset(vis, 0, sizeof(vis));
    memset(ban, 0, sizeof(ban));
    for (int v : forbidden) {
      vis[v] = 1;
      ban[v] = 1;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        q;
    q.emplace(0, 0);

    while (q.size()) {
      auto [steps, node] = q.top();
      q.pop();
      if (a >= b && node > x) {
        continue;
      }
      if (node == x) {
        return steps;
      }
      if (!vis[node]) {
        vis[node] = 1;
        if (node + a <= 6000 && !vis[node + a]) {
          q.emplace(steps + 1, node + a);
        }
        if (node + a - b <= 6000 && node + a - b >= 0 && !vis[node + a - b] &&
            !(node + a <= 2000 && ban[node + a])) {
          q.emplace(steps + 2, node + a - b);
        }
      }
    }
    return -1;
  }
};
// @lc code=end
