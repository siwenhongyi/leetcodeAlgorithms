/*
 * @lc app=leetcode.cn id=1313 lang=cpp
 *
 * [1313] 解压缩编码列表
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  vector<int> decompressRLElist(vector<int>& nums) {
    int n = nums.size();
    vector<int> res;
    int i, j, k;
    for (i = 0, j = 1; j < n; i = j + 1, j = i + 1) {
      k = 0;
      while (k++ < nums[i]) res.push_back(nums[j]);
    }
    return res;
  }
};
// @lc code=end
