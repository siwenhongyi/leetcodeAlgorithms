/*
 * @lc app=leetcode.cn id=643 lang=cpp
 *
 * [643] 子数组最大平均数 I
 */
#include "head.h"
// @lc code=start
class Solution {
 public:
  double findMaxAverage(vector<int>& nums, int k) {
    int n = nums.size();
    double sum = 0;
    for (int i = 0; i < k; i++) sum += nums[i];
    double res = sum / k;
    for (int i = k; i < n; i++) {
      sum = sum - nums[i - k] + nums[i];
      res = max(res, sum / k);
    }
    return res;
  }
};
// @lc code=end
