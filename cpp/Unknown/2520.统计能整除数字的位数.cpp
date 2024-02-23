/*
 * @lc app=leetcode.cn id=2520 lang=cpp
 *
 * [2520] 统计能整除数字的位数
 */

#include "head.h"
using namespace std;

// @lc code=start
class Solution {
 public:
  int countDigits(int num) {
    int res = 0, t = num, r;
    while (t) {
      r = t % 10;
      t /= 10;
      if (num % r == 0) res++;
    }
    return res;
  }
};
// @lc code=end
