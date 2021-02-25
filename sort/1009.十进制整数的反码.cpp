/*
 * @lc app=leetcode.cn id=1009 lang=cpp
 *
 * [1009] 十进制整数的反码
 */
#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  int bitwiseComplement(int N) {
    if (N == 0) return 1;
    int p = 32, num = N;
    while (num) {
      p--;
      num = num >> 1;
    }
    return ~(N << p) >> p;
  }
};
// @lc code=end
