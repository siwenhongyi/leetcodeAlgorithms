/*
 * @lc app=leetcode.cn id=689 lang=cpp
 *
 * [689] 三个无重叠子数组的最大和
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
    size_t n = nums.size();
    int sum1, sum2, sum3;
    int maxSum1, maxSum12, maxSum;
    int index[4];
    memset(index, 0x00, sizeof index);
    sum1 = sum2 = sum3 = maxSum1 = maxSum12 = maxSum = 0;
    vector<int> res;
    for (size_t i = 2 * k; i < n; i++) {
      sum1 += nums[i - 2 * k];
      sum2 += nums[i - k];
      sum3 += nums[i];
      if (i < 3 * k - 1) continue;
      if (sum1 > maxSum1) {
        maxSum1 = sum1;
        index[0] = i - 3 * k + 1;
      }
      if (sum2 + maxSum1 > maxSum12) {
        index[1] = index[0];
        index[2] = i - 2 * k + 1;
        maxSum12 = sum2 + maxSum1;
      }
      if (sum3 + maxSum12 > maxSum) {
        index[3] = i - k + 1;
        maxSum = sum3 + maxSum12;
        res = {index[1], index[2], index[3]};
      }
      // 每次i移动一个位置，然后改变3个滑动窗口的值
      sum1 -= nums[i - 3 * k + 1];
      sum2 -= nums[i - 2 * k + 1];
      sum3 -= nums[i - k + 1];
    }
    vector<int> a{1, 2, 3, 4}, b{2, 3, 5, 6}, c{0, 0};
    set_intersection(a.begin(), a.end(), b.begin(), b.end(), c.begin());
    for (auto& it : c) cout << it;
    return res;
  }
};
// @lc code=end
