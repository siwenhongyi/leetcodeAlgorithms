/*
 * @lc app=leetcode.cn id=565 lang=cpp
 *
 * [565] 数组嵌套
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  int arrayNesting(vector<int>& nums) {
    int res = 0;
    if (!nums.size()) return res;
    vector<bool> visited(nums.size(), false);
    int pre, n = nums.size();
    for (auto i : nums) {
      int index = i;
      int t = 0;
      while (!visited[index]) {
        t++;
        visited[index] = true;
        index = nums[index];
      }
      if (t > res) res = t;
    }
    return res;
  }
};

// @lc code=end
