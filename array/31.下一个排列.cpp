/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  void nextPermutation(vector<int>& nums) {
    if (nums.size() <= 1) return;
    bool t = false;
    int index = nums.size() - 2;
    while (index >= 0 && nums[index] >= nums[index + 1]) index--;
    if (index >= 0) {
      int j = nums.size() - 1;
      while (j >= 0 && nums[j] <= nums[index]) j--;
      swap(nums[index], nums[j]);
    }
    reverse(nums.begin() + index + 1, nums.end());
  }
};

// @lc code=end
