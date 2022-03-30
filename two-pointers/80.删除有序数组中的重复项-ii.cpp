/*
 * @lc app=leetcode.cn id=80 lang=cpp
 *
 * [80] 删除有序数组中的重复项 II
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    // try dont use it
    unordered_map<int, int> pos;
    int index = 1, n = nums.size();
    if (n <= 2) return n;
    int pre = nums[0], cnt = 1;
    for (int i = 1; i < n; i++) {
      if (nums[i] == pre) {
        if (++cnt <= 2) nums[index++] = nums[i];
      } else
        nums[index++] = pre = nums[i], cnt = 1;
    }
    // nums.resize(index + 1);
    return index;
  }
};
// @lc code=end
