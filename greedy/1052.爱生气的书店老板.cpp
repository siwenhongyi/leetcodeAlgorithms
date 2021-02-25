/*
* @lc app=leetcode.cn id=1052 lang=cpp
*
* [1052] 爱生气的书店老板
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  int maxSatisfied(vector<int>& cust, vector<int>& g, int x) {
    int n = cust.size();
    int res = 0, ans = 0;
    for (int i = 0; i < n; i++) {
      if (!g[i]) res += cust[i];
    }
    if (!x) return res;
    ans = res;
    for (int i = 0; i < min(x, n); i++) ans += g[i] ? cust[i] : 0;
    res = max(res, ans);
    for (int i = x; i < n; i++) {
      if (g[i - x]) ans -= cust[i - x];
      if (g[i]) ans += cust[i];
      res = max(res, ans);
    }
    return res;
  }
};
// @lc code=end

