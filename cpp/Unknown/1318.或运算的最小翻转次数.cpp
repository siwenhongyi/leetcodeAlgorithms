/*
 * @lc app=leetcode.cn id=1318 lang=cpp
 *
 * [1318] 或运算的最小翻转次数
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  int minFlips(int a, int b, int c) {
    if ((a | b) == c) return 0;
    bitset<32> x(a), y(b), z(c);
    int m = max(a, max(b, c));
    int n = 0, res = 0;
    while (pow(2, n) < m) n++;
    // n -= 1;
    for (int i = 0; i <= n; i++) {
      if ((x[i] | y[i]) == z[i])
        continue;
      else if (z[i])
        res++;
      else
        res += x[i] + y[i];
    }
    return res;
  }
};

// @lc code=end
