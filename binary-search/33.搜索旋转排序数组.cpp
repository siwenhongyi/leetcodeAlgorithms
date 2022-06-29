/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */
#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  int search(vector<int>& nums, int target) {
    int n = nums.size();
    if (!n) return -1;
    int l = 0, r = n;
    while (l < r) {
      auto&& mid = l + (r - l) / 2;
      if (nums[mid] == target) return mid;
      if (nums[mid] > nums[0]) {
        if (nums[mid] >= target && target >= nums[0])
          r = mid;
        else
          l = mid + 1;
      } else {
        if (target <= nums[n - 1] && target >= nums[mid])
          l = mid + 1;
        else
          r = mid;
      }
    }
    return -1;
  }
};
// @lc code=end
