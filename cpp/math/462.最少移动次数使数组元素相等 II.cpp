/*
 * @lc app=leetcode.cn id=462 lang=cpp
 *
 * [462] 最少移动次数使数组元素相等 II
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  int minMoves2(vector<int>& nums) {
    if (nums.empty()) return 0;
    sort(nums.begin(), nums.end());
    int res = 0, mid = nums[nums.size() / 2];
    for (auto& i : nums) res += abs(i - mid);
    return res;
  }
};

// @lc code=end
