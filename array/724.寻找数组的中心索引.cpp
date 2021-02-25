/*
* @lc app=leetcode.cn id=724 lang=cpp
*
* [724] 寻找数组的中心索引
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  int pivotIndex(vector<int>& nums) {
    int sum = 0;
    for (auto& it : nums) sum += it;
    int l = 0, r = sum, n = nums.size();
    for (int i = 0; i < n; i++) {
      r -= nums[i];
      if (l == r) return i;
      l += nums[i];
    }
    return -1;
  }
};
// @lc code=end

