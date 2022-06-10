/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */
#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    int n = nums.size();
    if (n < 2) return {};
    unordered_map<int, int> pos;
    for (int i = 0; i < n; i++) {
      auto&& it = nums[i];
      if (pos.find(target - it) != pos.end()) {
        return {pos[target - it], i};
      }
      pos[it] = i;
    }
    return {};
  }
};
// @lc code=end
