/*
 * @lc app=leetcode.cn id=LCP 02 lang=cpp
 *
 * [LCP 02] 分式化简
 */
#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  int gcd(int x, int y) { return y == 0 ? x : gcd(y, x % y); }
  void fun(int x, pair<int, int>& t) {
    t.first += x * t.second;
    swap(t.first, t.second);
  }
  vector<int> fraction(vector<int>& v) {
    if (v.size() == 1) return {v.back(), 1};
    int n = v.size();
    int t;
    pair<int, int> res = make_pair(1, v.back());
    for (int i = n - 2; i >= 0; i--) {
      fun(v[i], res);
      t = gcd(res.first, res.second);
      res.first /= t;
      res.second /= t;
    }
    return {res.second, res.first};
  }
};
// @lc code=end
