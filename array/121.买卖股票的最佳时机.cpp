/*
* @lc app=leetcode.cn id=121 lang=cpp
*
* [121] 买卖股票的最佳时机
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  int maxProfit(vector<int>& p) {
    int n = p.size();
    if (n < 2) return 0;
    int m = p[0], res = 0;
    for (int i = 1; i < n; i++) {
      res = max(res, p[i] - m);
      m = min(m, p[i]);
    }
    return res;
  }
};
// @lc code=end

