/*
 * @lc app=leetcode.cn id=1515 lang=cpp
 *
 * [1515] 服务中心的最佳位置
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  vector<vector<int>> pos;
  int n;
  double o_sum(double x, double y) {
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
      sum += sqrt((x - pos[i][0]) * (x - pos[i][0]) +
                  (y - pos[i][1]) * (y - pos[i][1]));
    }
    return sum;
  }
  double funx(double x) {
    double l = 0.0, r = 100.0;
    double midl, midr;
    for (int i = 0; i <= 100; i++) {
      midl = (l + r) / 2.0;
      midr = (midl + r) / 2.0;
      if (o_sum(x, midl) < o_sum(x, midr))
        r = midr;
      else
        l = midl;
    }
    return o_sum(x, l);
  }
  double getMinDistSum(vector<vector<int>>& arr) {
    double res = 0;
    double l = 0.0, r = 100.0;
    double midl, midr;
    pos.swap(arr);
    n = pos.size();
    for (int i = 0; i <= 100; i++) {
      midl = (l + r) / 2.0;
      midr = (midl + r) / 2.0;
      if (funx(midl) < funx(midr))
        r = midr;
      else
        l = midl;
    }
    return funx(l);
  }
};
// @lc code=end
