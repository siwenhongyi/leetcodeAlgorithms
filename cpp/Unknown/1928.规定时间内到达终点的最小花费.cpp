/*
 * Created by 张明利 on 10-10-2024, 10:25:53 AM
 */

/*
 * @lc app=leetcode.cn id=1928 lang=cpp
 *
 * [1928] 规定时间内到达终点的最小花费
 */

#include "head.h"
using namespace std;

// @lc code=start
class Solution {
  int target;
  vector<set<pair<int, int>>> e;
  vector<int> cost;
  int mt;

  bool dfs(const int& now, const int& times, const int& c,
           unordered_set<int>& v) {
    if (times > mt) return false;
    if (c < 0) return false;
    if (now == target) return true;
    for (const auto& it : e[now]) {
      if (v.count(it.second)) continue;
      v.insert(it.second);
      if (dfs(it.second, times + it.first, c - cost[it.second], v)) {
        v.erase(it.second);
        return true;
      }
      v.erase(it.second);
    }
    return false;
  }

 public:
  int minCost(int maxTime, vector<vector<int>>& edges,
              vector<int>& passingFees) {
    int n = passingFees.size();
    target = n - 1;
    cost.swap(passingFees);
    vector<set<pair<int, int>>> et(n);
    int l = cost.back(), r = 0;
    mt = maxTime;
    for (const auto& it : cost) {
      r += it;
    }
    for (const auto& it : edges) {
      if (it[2] < maxTime) {
        et[it[0]].insert({it[2], it[1]});
        et[it[1]].insert({it[2], it[0]});
      }
    }
    e.swap(et);
    int res = -1;
    unordered_set<int> v;
    while (l <= r) {
      v.clear();
      int m = (l + r) / 2;
      v.insert(0);
      if (dfs(0, 0, m - cost[0], v)) {
        res = m;
        r = m - 1;
      } else {
        l = m + 1;
      }
    }
    return res;
  }
};
// @lc code=end
