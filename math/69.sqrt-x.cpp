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
    double res = 1;
    while (abs(res * res - x) > 0.1) {
      res = (res + x / res) / 2.0;
    }
    return int(res);
  }
};
// @lc code=end
