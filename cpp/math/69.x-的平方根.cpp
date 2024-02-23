/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] Sqrt(x)
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  int mySqrt(int x) {
    if (x == 0) {
      return 0;
    }

    double C = x, x0 = x;
    while (true) {
      double xi = 0.5 * (x0 + C / x0);
      if (abs(x0 - xi) < 1e-7) {
        break;
      }
      x0 = xi;
    }
    return int(x0);
  }
};
// @lc code=end
