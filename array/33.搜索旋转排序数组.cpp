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
    if (!nums.size()) return -1;
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
      int root = nums[l];
      if (root == target) return l;
      int mid = l + 1;
      while (mid < nums.size() && nums[mid] > nums[l]) mid++;
      if (root < target) {
        l++;
        r = mid - 1;
      } else
        l = mid;
    }
    return -1;
  }
};

// @lc code=end
