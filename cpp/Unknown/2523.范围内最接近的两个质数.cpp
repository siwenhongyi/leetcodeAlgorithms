/*
 * @lc app=leetcode.cn id=2523 lang=cpp
 *
 * [2523] 范围内最接近的两个质数
 */

#include "head.h"
using namespace std;

// @lc code=start
class Solution {
  static vector<int> p;
  void helper() {
    p[0] = p[1] = 0;
    for (int i = 2; i <= 1e6; i++) {
      if (p[i] == 0) continue;
      for (int j = i + i; j <= 1e6; j += i) p[j] = 0;
    }
  }

 public:
  vector<int> closestPrimes(int left, int right) {
    if (right == left) return {-1, -1};
    helper();
    int tr, l = -1, r = 1 << 30 - 1;
    while (left < right) {
      while (left < right && p[left] == 0) {
        left++;
        continue;
      }
      tr = left + 1;
      while (tr <= right && p[tr] == 0) tr++;
      if (tr > right) break;
      if (tr - left < r - l) l = left, r = tr;
      left = tr;
    }
    if (l == -1) return {-1, -1};
    return {l, r};
  }
};

vector<int> Solution::p = vector<int>(1e6 + 1, 1);

// @lc code=end
