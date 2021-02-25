/*
 * @lc app=leetcode.cn id=638 lang=cpp
 *
 * [638] 大礼包
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
  vector<vector<int>> v;
  vector<int> p;
  int m, len;

 public:
  void dfs(vector<int>& need, int index, int cost) {
    if (cost > m) return;
    if (index >= len) {
      for (int i = 0; i < need.size(); i++) {
        if (need[i]) cost += need[i] * p[i];
      }
      if (m > cost) m = cost;
      return;
    }
    vector<int> tneed(need);
    int flag = 1;
    for (int i = 0; i < v[index].size() - 1; i++) {
      if (v[index][i] > need[i]) {
        flag = 0;
        break;
      }
      tneed[i] -= v[index][i];
    }
    dfs(need, index + 1, cost);
    if (flag) dfs(tneed, index, cost + v[index].back());
  }
  int shoppingOffers(vector<int>& price, vector<vector<int>>& special,
                     vector<int>& needs) {
    if (needs.empty()) return 0;
    p.swap(price);
    m = (1 << 31) - 1;
    int n = p.size(), flag;
    for (auto& c : special) {
      flag = 1;
      for (int i = 0; i < n; i++)
        if (c[i] > needs[i]) {
          flag = 0;
          break;
        }
      if (flag) v.push_back(c);
    }
    len = v.size();
    dfs(needs, 0, 0);
    return m;
  }
};
// @lc code=end
