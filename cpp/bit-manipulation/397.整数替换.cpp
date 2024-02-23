/*
 * @lc app=leetcode.cn id=397 lang=cpp
 *
 * [397] 整数替换
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  int integerReplacement(int n) {
    if (n == 1) return 0;
    if (n % 2) {
      long long x = n;
      return 2 + min(integerReplacement((x + 1) / 2),
                     integerReplacement((x - 1) / 2));
    } else
      return 1 + integerReplacement(n / 2);
  }
};

// @lc code=end
