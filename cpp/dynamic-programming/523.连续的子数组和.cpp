/*
 * @lc app=leetcode.cn id=523 lang=cpp
 *
 * [523] 连续的子数组和
 */
#include "head.h"
// @lc code=start
class Solution {
  using ll = long long;

 public:
  bool checkSubarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    ll sum = nums[0];
    unordered_map<int, int> pos;
    pos[sum % k] = 0;
    int r;
    for (int i = 1; i < n; i++) {
      sum += nums[i];
      r = sum % k;
      if (!r) return true;
      if (pos.count(r)) {
        if (i - pos[r] >= 2) return true;
      } else
        pos[r] = i;
    }
    return false;
  }
};
// @lc code=end
