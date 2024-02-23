/*
 * @lc app=leetcode.cn id=1512 lang=cpp
 *
 * [1512] 好数对的数目
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  int numIdenticalPairs(vector<int>& nums) {
    if (nums.size() <= 1) return 0;
    map<int, vector<int>> pos;
    for (int i = 0; i < nums.size(); i++) {
      pos[nums[i]].push_back(i);
    }
    int res = 0;
    for (auto& iter : pos)
      res += (iter.second.size() * (iter.second.size() - 1)) / 2;
    return res;
  }
};

// @lc code=end
