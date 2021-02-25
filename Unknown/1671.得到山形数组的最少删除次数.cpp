/*
 * @lc app=leetcode.cn id=1671 lang=cpp
 *
 * [1671] 得到山形数组的最少删除次数
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  int minimumMountainRemovals(vector<int>& nums) {
    int res = INT_MAX;
    int n = nums.size();
    vector<int> up(n), down(n);
    up[0] = down[n - 1] = 1;
    // 每一位为结束  最长递增子序列
    for (int i = 1; i < n; i++) {
      up[i] = 1;
      for (int j = 0; j < i; j++)
        if (nums[j] < nums[i]) up[i] = max(up[i], up[j] + 1);
    }
    // 每一位为结束  倒着最长递增子序列
    for (int i = n - 2; i >= 0; i--) {
      down[i] = 1;
      for (int j = n - 1; j > i; j--)
        if (nums[j] < nums[i]) down[i] = max(down[i], down[j] + 1);
    }
    int a, b;
    for (int i = 1; i < n - 1; i++) {
      a = i + 1 - up[i];
      b = (n - i) - down[i];
      res = min(res, a + b);
    }
    return res;
  }
};
// @lc code=end
