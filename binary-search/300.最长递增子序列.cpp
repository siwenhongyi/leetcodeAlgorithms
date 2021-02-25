/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    if (n <= 1) return n;
    vector<int> res(n, 1);
    int ret = 1, t;
    for (int i = 1; i < n; i++) {
      t = nums[i];
      for (int j = 0; j < i; j++) {
        if (nums[j] < t) res[i] = max(res[i], res[j] + 1);
      }
      ret = max(ret, res[i]);
    }
    return ret;
  }
};

// @lc code=end
