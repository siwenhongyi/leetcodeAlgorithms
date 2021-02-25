/*
 * @lc app=leetcode.cn id=1137 lang=cpp
 *
 * [1137] 第 N 个泰波那契数
 */

#include "head.h"
using namespace std;
// @lc code=start
#define maxn 65535
int res[40] = {0, 1, 1};
class Solution {
 public:
  int tribonacci(int n) {
    if (n < 3) return res[n];
    for (int i = 3; i <= 37; i++) res[i] = res[i - 1] + res[i - 2] + res[i - 3];
    return res[n];
  }
};

// @lc code=end
