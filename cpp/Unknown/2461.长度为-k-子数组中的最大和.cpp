/*
 * @lc app=leetcode.cn id=2461 lang=cpp
 *
 * [2461] 长度为 K 子数组中的最大和
 */

#include "head.h"
using namespace std;

// @lc code=start
class Solution {
  using ll = long long;

 public:
  long long maximumSubarraySum(vector<int>& nums, int k) {
    ll res = 0, temp = 0;
    int n = nums.size(), l = 0, r = 0;
    unordered_map<int, int> cnt;
    while (r < n) {
      auto&& num = nums[r];
      if (cnt[num]++ != 0) {
        while (l < r && nums[l] != num) {
          temp -= nums[l];
          cnt[nums[l++]]--;
        }
        temp -= nums[l];
        cnt[nums[l++]]--;
      }
      temp += num;
      if (r - l + 1 == k) {
        res = max(res, temp);
        temp -= nums[l];
        cnt[nums[l++]]--;
      }
      r++;
    }
    return res;
  }
};
// @lc code=end
