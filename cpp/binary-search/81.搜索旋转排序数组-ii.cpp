/*
 * @lc app=leetcode.cn id=81 lang=cpp
 *
 * [81] 搜索旋转排序数组 II
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  bool search(vector<int>& nums, int target) {
    if (nums.empty()) return false;
    if (target == nums.front() || target == nums.back()) return true;
    bool less_front = target<nums.front(), greater_back = target> nums.back();
    auto &&front = nums.front(), &&back = nums.back();
    int l = 0, r = nums.size();
    while (l < r) {
      auto&& mid = l + (r - l) / 2;
      auto&& t = nums[mid];
      if (nums[mid] == target) return true;
      if (nums[l] == t && nums[r - 1] == t) {
        l++;
        r--;
      } else if (t >= nums[l]) {
        if (nums[l] <= target && t >= target)
          r = mid;
        else
          l = mid + 1;
      } else {
        if (t <= target && nums[r - 1] >= target)
          l = mid + 1;
        else
          r = mid;
      }
    }
    return false;
  }
};
// @lc code=end
