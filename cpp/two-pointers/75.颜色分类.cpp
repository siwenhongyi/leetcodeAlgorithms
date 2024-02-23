/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  void sortColors(vector<int>& nums) {
    int l = -1, r = nums.size(), index = 0;
    while (index < r) {
      if (index == l) {
        index++;
        continue;
      }
      switch (nums[index]) {
        case 0:
          swap(nums[++l], nums[index]);
          break;
        case 2:
          swap(nums[--r], nums[index]);
          break;
        default:
          index++;
          break;
      }
    }
    return;
  }
};
// @lc code=end
