/*
 * @lc app=leetcode.cn id=829 lang=cpp
 *
 * [829] 连续整数求和
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  int consecutiveNumbersSum(int N) {
    if (N <= 2) return 1;
    int num = 1;
    int n = 2 * N;
    for (int i = 2; i <= sqrt(n); i++) {
      if (n % i == 0) {
        int end = (n / i + i - 1) / 2;
        int start = end - n / i + 1;
        if ((start + end) * (end - start + 1) == n) num++;
      }
    }
    return num;
  }
};

// @lc code=end
