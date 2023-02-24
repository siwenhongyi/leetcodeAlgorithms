/*
 * @lc app=leetcode.cn id=2357 lang=cpp
 *
 * [2357] 使数组中所有元素都等于零 Easy (74.26%)
 */

#include "head.h"
using namespace std;

// @lc code=start
class Solution {
 public:
  int minimumOperations(vector<int>& nums) {
    set<int> res(nums.begin(), nums.end());
    if (res.size() && *res.begin() == 0) res.erase(res.begin());
    return res.size();
  }
};
// @lc code=end
