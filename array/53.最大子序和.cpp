/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */
#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    if (nums.size() == 1) return nums.front();
    int res = nums[0], n = nums.size(), t = 0;
    for (int i = 0; i < n; i++) {
      t += nums[i];
      res = max(res, t);
      t = max(t, 0);
    }
    return res;
  }
};
// @lc code=end
