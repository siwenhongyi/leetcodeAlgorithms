/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  int removeElement(vector<int>& nums, int val) {
    vector<int>::iterator iter = nums.begin();
    for (; iter != nums.end();)
      if (*iter == val)
        iter = nums.erase(iter);
      else
        iter++;
    return nums.size();
  }
};
// @lc code=end
