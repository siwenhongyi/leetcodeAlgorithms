/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */
#include "head.h"
// @lc code=start
class Solution {
 public:
  double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
    for (auto& it : b) a.push_back(it);
    sort(a.begin(), a.end());
    int n = a.size();
    if (n & 1) return a[n / 2];
    return (a[n / 2] + a[n / 2 - 1]) / 2.0;
  }
};
// @lc code=end
