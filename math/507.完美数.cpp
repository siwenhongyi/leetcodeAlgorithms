/*
 * @lc app=leetcode.cn id=507 lang=cpp
 *
 * [507] 完美数
 */

#include "head.h"
using namespace std;
// @lc code=start

class Solution {
 public:
  bool checkPerfectNumber(int num) {
    if (num == 1) return false;
    int res = 1;
    for (int i = 2; i <= sqrt(num); i++) {
      if (num % i == 0) {
        res += i + num / i;
      }
    }
    return res == num;
  }
};
// @lc code=end
