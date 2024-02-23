/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  void moveZeroes(vector<int>& nums) {
    int index = 0, n = nums.size();
    for (auto& i : nums)
      if (i) swap(nums[index++], i);
  }
};
// @lc code=end
