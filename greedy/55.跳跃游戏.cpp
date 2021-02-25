/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  bool canJump(vector<int>& nums) {
    int r = 0;
    int i = 0, n = nums.size() - 1;
    for (int i = 0; i <= n; i++) {
      if (i <= r) {
        r = max(r, i + nums[i]);
        if (r >= n) break;
      } else
        return false;
    }
    return r >= n;
  }
};
// @lc code=end
