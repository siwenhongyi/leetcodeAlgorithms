/*
 * @lc app=leetcode.cn id=525 lang=cpp
 *
 * [525] 连续数组
 */
#include "head.h"
// @lc code=start
class Solution {
 public:
  int findMaxLength(vector<int>& nums) {
    int sum = 0, n = nums.size(), res = 0;
    unordered_map<int, int> pos;
    pos[0] = -1;
    for (int i = 0; i < n; ++i) {
      sum += nums[i] ? 1 : -1;
      if (pos.count(sum))
        res = max(res, i - pos[sum]);

      else
        pos[sum] = i;
    }
    return res;
  }
};
// @lc code=end
