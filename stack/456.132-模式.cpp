/*
 * @lc app=leetcode.cn id=456 lang=cpp
 *
 * [456] 132模式
 */
#include "head.h"
// @lc code=start
class Solution {
 public:
  bool find132pattern(vector<int>& nums) {
    if (nums.size() < 3) return false;
    int n = nums.size(), m = INT_MIN;
    stack<int> q;
    q.push(nums.back());
    for (int i = n - 1; i >= 0; --i) {
      if (nums[i] < m) return true;
      while (q.size() && nums[i] > q.top()) {
        m = q.top();
        q.pop();
      }
      if (nums[i] > m) q.push(nums[i]);
    }
    return false;
  }
};
// @lc code=end
