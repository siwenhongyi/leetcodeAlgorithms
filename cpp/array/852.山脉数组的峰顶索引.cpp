/*
 * @lc app=leetcode.cn id=852 lang=cpp
 *
 * [852] 山脉数组的峰顶索引
 */
#include "head.h"
using namespace std;

// @lc code=start
class Solution {
 public:
  int peakIndexInMountainArray(vector<int>& arr) {
    int l = 0, r = arr.size() - 1, mid;
    int a, b, c;
    if (r == 2) return 1;
    while (l <= r) {
      mid = l + (r - l) / 2;
      a = arr[mid - 1], b = arr[mid], c = arr[mid + 1];
      if (b > a && b > c) return mid;
      if (c < b) {
        r = mid;
      } else {
        l = mid;
      }
    }
    return 1;
  }
};
// @lc code=end
