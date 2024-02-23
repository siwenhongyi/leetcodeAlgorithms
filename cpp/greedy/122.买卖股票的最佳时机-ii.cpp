/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 private:
  using pii = pair<int, int>;

 public:
  int maxProfit(vector<int>& prices) {
    // 任意次交易，最大收益
    int n = prices.size();
    if (n == 0) return 0;
    // // first:持有股票 second:不持有股票
    pii s{0, -prices[0]}, t;
    for (int i = 1; i < n; i++) {
      t.first = max(s.first, s.second + prices[i]);
      t.second = max(s.second, s.first - prices[i]);
      s = t;
    }
    return s.first;
  }
};
// @lc code=end
