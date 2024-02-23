/*
 * @lc app=leetcode.cn id=1005 lang=cpp
 *
 * [1005] K 次取反后最大化的数组和
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  int largestSumAfterKNegations(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int index = 0;
    while (index < n && nums[index] < 0 && k--) {
      nums[index++] = -nums[index];
    }
    // 机会用完 或者负数反转完有0
    if (k == -1 || !nums[index]) return accumulate(nums.begin(), nums.end(), 0);
    // 全是负数
    if (index == n) {
      if (k % 2) nums.back() = -nums.back();
      return accumulate(nums.begin(), nums.end(), 0);
    }
    //有正数 index是最小的正数 index可能为0(全是正数)
    if (k % 2) {
      index = (index != 0 && nums[index - 1] < nums[index]) ? index - 1 : index;
      nums[index] = -nums[index];
    }
    return accumulate(nums.begin(), nums.end(), 0);
  }
};
// @lc code=end
