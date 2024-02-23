/*
 * @lc app=leetcode.cn id=697 lang=cpp
 *
 * [697] 数组的度
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  int findShortestSubArray(vector<int>& nums) {
    map<int, vector<int>> pos;
    map<int, int> fre;
    int est = 0, n = nums.size();
    for (int i = 0; i < n; i++) {
      est = max(est, ++fre[nums[i]]);
      pos[nums[i]].push_back(i);
    }
    int res = INT_MAX;
    for (auto& it : pos) {
      auto&& [a, b] = it;
      if (b.size() < est) continue;
      res = min(res, b[est - 1] - b[0] + 1);
    }
    return res;
  }
};
// @lc code=end
