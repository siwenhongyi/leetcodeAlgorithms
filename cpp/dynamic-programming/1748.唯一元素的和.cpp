/*
 * @lc app=leetcode.cn id=1748 lang=cpp
 *
 * [1748] 唯一元素的和
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  int sumOfUnique(vector<int>& nums) {
    int res = 0;
    map<int, int> pos;
    for (auto& it : nums) pos[it]++;
    for (auto& it : pos)
      if (it.second == 1) res += it.first;
    return res;
  }
};
// @lc code=end
