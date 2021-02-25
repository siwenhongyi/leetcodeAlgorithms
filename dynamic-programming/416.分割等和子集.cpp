/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  bool canPartition(vector<int> &nums) {
    int sum = 0, n = nums.size(), m = 0;
    if (n < 2) return false;
    for (auto &it : nums) sum += it, m = max(m, it);
    if (sum & 1 || m > sum / 2) return false;
    sum /= 2;
    vector<bool> first(sum + 1), second(sum + 1);
    first[0] = first[nums[0]] = true;
    for (int i = 1; i < n; i++) {
      auto &it = nums[i];
      for (int j = 1; j <= sum; j++) {
        if (j >= it)
          second[j] = first[j] | first[j - it];
        else
          second[j] = first[j];
      }
      first.swap(second);
    }
    return first.back();
  }
};
// @lc code=end
