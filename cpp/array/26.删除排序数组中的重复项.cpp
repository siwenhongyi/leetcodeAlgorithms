/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除排序数组中的重复项
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    if (nums.size() <= 1) return nums.size();
    auto iter = nums.begin() + 1;
    for (; iter != nums.end();) {
      if (*iter == *(iter - 1))
        iter = nums.erase(iter);
      else
        iter++;
    }
    return nums.size();
  }
};
// @lc code=end
