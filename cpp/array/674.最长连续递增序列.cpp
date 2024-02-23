/*
 * @lc app=leetcode.cn id=674 lang=cpp
 *
 * [674] 最长连续递增序列
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  int findLengthOfLCIS(vector<int>& nums) {
    int res = 0;
    int i = 0;
    while (i < nums.size()) {
      int t = i, j = i + 1;
      while (j < nums.size() && nums[j] > nums[t]) t = j++;
      res = max(res, j - i);
      i = j;
    }
    return res;
  }
};

// @lc code=end
