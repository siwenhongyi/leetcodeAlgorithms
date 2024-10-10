/*
 * Created by 张明利 on 10-9-2024, 8:24:30 PM
 */

/*
 * @lc app=leetcode.cn id=1870 lang=cpp
 *
 * [1870] 准时到达的列车最小时速
 */

#include <cmath>

#include "head.h"
using namespace std;

// @lc code=start
class Solution {
  inline bool check(const vector<int> d, const int& sp, const double& a) const {
    double t = 0;
    for (int i = 0; i < d.size() - 1; i++) {
      auto&& c = double(d[i]) / sp;
      if (c != int(c)) c = int(c) + 1;
      t += c;
    }
    t += double(d.back()) / sp;
    // cout << "speed=" << sp << "time=" << t << "check=" << a << endl;
    return t <= a;
  }

 public:
  int minSpeedOnTime(vector<int>& dist, double hour) {
    int n = dist.size();
    if (n - 1 >= hour) return -1;
    int l = 1, r = *max_element(dist.begin(), dist.end());
    if (hour != int(hour)) {
      auto&& p = hour - int(hour);
      auto&& q = r / p;
      r += int(q) + 1;
    }
    int res = r;
    while (l <= r) {
      int m = (l + r) / 2;
      if (check(dist, m, hour)) {
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
