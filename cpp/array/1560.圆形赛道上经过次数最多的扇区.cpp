/*
 * @lc app=leetcode.cn id=1560 lang=cpp
 *
 * [1560] 圆形赛道上经过次数最多的扇区
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  vector<int> mostVisited(int n, vector<int>& rounds) {
    if (rounds.empty()) return {};
    int l, r;
    vector<int> num(n + 1, 0);
    for (int i = 1; i < rounds.size(); i++) {
      l = rounds[i - 1], r = rounds[i];
      // num[r]++;
      while (l != r) {
        num[l++]++;
        if (l == n + 1) l = 1;
      }
    }
    num[rounds.back()]++;
    vector<int> res;
    int m = *max_element(num.begin(), num.end());
    for (int i = 1; i <= n; i++)
      if (num[i] == m) res.push_back(i);
    return res;
  }
};
// @lc code=end
