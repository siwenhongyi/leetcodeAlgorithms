/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  int rob(vector<int>& nums) {
    int n = nums.size();

    if (n == 0) return 0;

    if (n == 1) return nums[0];

    if (n == 2) return max(nums.front(), nums.back());

    vector<int> d(n, 0), p(n, 0);

    d[0] = nums[0], d[1] = max(nums[0], nums[1]);

    p[1] = nums[1], p[2] = max(nums[1], nums[2]);

    for (int i = 2; i < n; i++) {
      if (i != n - 1) {
        d[i] = max(d[i - 2] + nums[i], d[i - 1]);
      }

      if (i > 2) {
        p[i] = max(p[i - 2] + nums[i], p[i - 1]);
      }
    }

    return max(d[n - 2], p.back());
  }
};
// @lc code=end
