/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */
#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    int i = 0, n = nums.size();
    while (i < n) {
      auto&& target = -nums[i];
      int l = i + 1, r = n - 1;
      // if (nums[l] + nums[r] > target) break;
      while (l < r) {
        auto&& curr_target = nums[l] + nums[r];
        if (curr_target == target) {
          res.push_back({nums[l], nums[i], nums[r]});
          while (l < r && nums[l] == res.back().front()) l++;
          while (l < r && nums[r] == res.back().back()) r--;
        } else if (curr_target > target) {
          r--;
        } else {
          l++;
        }
      }
      while (i + 1 < n && nums[i] == nums[i + 1]) i++;
      i++;
    }
    return res;
  }
};
// @lc code=end
