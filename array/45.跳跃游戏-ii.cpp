/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II Medium (45.22%)
 */

#include "head.h"
using namespace std;

// @lc code=start
class Solution {
  int dpJump(vector<int>& nums) {
    int n = nums.size(), m, x = 1 << 30;
    nums.back() = 0;
    for (int i = n - 2; i >= 0; i--) {
      if (nums[i] == 0) {
        nums[i] = x;
        continue;
      }
      m = nums[i + 1];
      for (int j = 1; j <= nums[i]; j++) {
        m = min(m, nums[i + j]);
        if (i + j == n - 1) break;
      }
      nums[i] = m + 1;
    }
    return nums[0];
  }

 public:
  int jump(vector<int>& nums) {
    int mf = 0, max_right = 0, res = 0, n = nums.size();
    for (int i = 0; i < n - 1; i++) {
      mf = max(mf, i + nums[i]);
      if (i == max_right) max_right = mf, res++;
    }
    return res;
  }
};
// @lc code=end
