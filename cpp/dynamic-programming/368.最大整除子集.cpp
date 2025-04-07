/*
 * @lc app=leetcode.cn id=368 lang=cpp
 *
 * [368] 最大整除子集
 */

#include "head.h"
using namespace std;

// @lc code=start
// 2025:04:06 23:18:43
class Solution {
 public:
  vector<int> largestDivisibleSubset(vector<int>& nums) {
    int n = nums.size();
    if (n <= 1) {
      return nums;
    }
    sort(nums.begin(), nums.end());
    vector<int> dp(n, 1), prev(n, 0);
    for (int i = 0; i < n; i++) {
      dp[i] = 1, prev[i] = i;
    }
    int ans = 0;
    for (int i = 1; i < n; i++) {
      for (int j = i - 1; j >= 0; j--) {
        if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
          dp[i] = dp[j] + 1;
          prev[i] = j;
        }
      }
      if (dp[i] > dp[ans]) {
        ans = i;
      }
    }
    vector<int> res;
    while (ans != prev[ans]) {
      res.push_back(nums[ans]);
      ans = prev[ans];
    }
    res.push_back(nums[ans]);

    return res;
  }
};
// @lc code=end
