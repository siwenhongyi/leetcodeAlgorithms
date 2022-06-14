/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */
#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  double findMedianSortedArrays(vector<int>& s, vector<int>& t) {
    int x = s.size(), y = t.size();
    int n = x + y;
    int mid = n / 2;
    if (!x) return (n & 1) ? t[mid] : (t[mid] + t[mid - 1]) / 2.0;
    if (!y) return (n & 1) ? s[mid] : (s[mid] + s[mid - 1]) / 2.0;
    int a = 0, b = 0;
    int ax, bx, pre = -1;
    double res = 0;
    while (true) {
      ax = a == x ? INT32_MAX : s[a];
      bx = b == y ? INT32_MAX : t[b];
      if (a + b == mid) {
        if (n & 1) return min(ax, bx);
        return (pre + min(ax, bx)) / 2.0;
      }
      if (ax < bx)
        pre = ax, a++;
      else
        pre = bx, b++;
    }
    return res;
  }
};
// @lc code=end
