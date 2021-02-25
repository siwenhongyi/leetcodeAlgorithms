/*
 * @lc app=leetcode.cn id=665 lang=cpp
 *
 * [665] 非递减数列
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  bool checkPossibility(vector<int>& nums) {
    int res = 0;
    int n = nums.size();
    for (int i = 0; i < n - 1 && res < 2; i++) {
      if (nums[i] > nums[i + 1]) {
        res++;
        if (i && nums[i + 1] < nums[i - 1])
          nums[i + 1] = nums[i];
        else
          nums[i] = nums[i + 1];
      }
    }
    return res < 2;
  }
};
// @lc code=end
