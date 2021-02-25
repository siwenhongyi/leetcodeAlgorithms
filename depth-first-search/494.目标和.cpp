/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  int n, k, res;
  vector<int> x;
  void dfs(int index, int ts) {
    if (index == n) {
      if (ts == k) res++;
      return;
    }
    dfs(index + 1, ts + x[index]);
    dfs(index + 1, ts - x[index]);
  }
  int findTargetSumWays(vector<int>& nums, int S) {
    n = nums.size();
    k = S;
    res = 0;
    x.swap(nums);
    dfs(0, 0);
    return res;
  }
};
// @lc code=end
