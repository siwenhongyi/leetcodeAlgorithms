/*
 * @lc app=leetcode.cn id=400 lang=cpp
 *
 * [400] 第 N 位数字
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 private:
  int func(int x) {
    int res = 0, pre_count = 1, num_count = 9;
    while (pre_count <= x) {
      res += pre_count++ * num_count;
      num_count *= 10;
    }
    return res;
  }

 public:
  int findNthDigit(int n) {
    int left = 1, right = 9, mid;
    while (left < right) {
      mid = left + (right - left) / 2;
      if (func(mid) < n)
        left = mid + 1;
      else
        right = mid;
    }
    int num_count = left, pre_count = func(left - 1);
    int index = n - pre_count - 1;
    left = pow(10, num_count - 1);
    int res = left + index / num_count;
    right = index % num_count;
    return (res / int(pow(10, num_count - right - 1))) % 10;
  }
};
// @lc code=end
