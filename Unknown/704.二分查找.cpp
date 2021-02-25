/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  int search(vector<int>& nums, int target) {
    if (nums.size() == 1) return nums[0] == target ? 0 : -1;
    int index = -1;
    int left = 0, right = nums.size() - 1, mid;
    while (left <= right) {
      mid = (left + right) / 2;
      if (nums[mid] == target) return mid;
      if (nums[mid] > target)
        right = mid - 1;
      else
        left = mid + 1;
    }
    return -1;
  }
};
// @lc code=end
