/*
 * @lc app=leetcode.cn id=1109 lang=cpp
 *
 * [1109] 航班预订统计
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
    vector<int> x, y, res;
    x.resize(n + 1, 0);
    y.resize(n + 1, 0);
    for (int i = 0; i < bookings.size(); i++) {
      x[bookings[i][0]] += bookings[i][2];
      y[bookings[i][1]] += bookings[i][2];
    }
    int num = x[1];
    res.push_back(num);
    for (int i = 2; i <= n; i++) {
      num = num + x[i] - y[i - 1];
      res.push_back(num);
    }
    return res;
  }
};

// @lc code=end
