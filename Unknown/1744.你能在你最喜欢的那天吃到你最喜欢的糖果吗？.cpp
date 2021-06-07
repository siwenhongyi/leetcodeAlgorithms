/*
 * @lc app=leetcode.cn id=1744 lang=cpp
 *
 * [1744] 你能在你最喜欢的那天吃到你最喜欢的糖果吗？
 */
#include "head.h"
// @lc code=start
class Solution {
  using ll = long long;

 public:
  vector<bool> canEat(vector<int>& cc, vector<vector<int>>& q) {
    int n = cc.size();
    vector<ll> psum(n + 1, 0);
    for (int i = 1; i <= n; ++i) psum[i] = psum[i - 1] + cc[i - 1];
    vector<bool> res;
    ll l, f;
    for (auto& it : q) {
      // cout << psum[it[0]] << ' ' << cc[it[0]] << endl;
      l = psum[it[0] + 1], f = psum[it[0]] / it[2];
      // cout << l << ' ' << f << endl;
      res.push_back((it[1] + 1 > f && it[1] + 1 <= l));
    }
    return res;
  }
};
// @lc code=end
