/*
 * @lc app=leetcode.cn id=1664 lang=cpp
 *
 * [1664] 生成平衡数组的方案数
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  int waysToMakeFair(vector<int>& nums) {
    int res[2] = {0, 0};
    int index = 1, n = nums.size(), ans = 0;
    while (index < n) {
      res[!(index % 2)] += nums[index];
      index++;
    }
    ans += res[0] == res[1];
    int a = nums[0], b = 0;
    index = 1;
    while (index < n) {
      res[!(index % 2)] -= nums[index];
      ans += (a + res[0]) == (b + res[1]);
      if (index % 2)
        b += nums[index];
      else
        a += nums[index];
      index++;
    }
    return ans;
  }
};
// @lc code=end
