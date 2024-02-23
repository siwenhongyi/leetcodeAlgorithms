/*
 * @lc app=leetcode.cn id=491 lang=cpp
 *
 * [491] 递增子序列
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  vector<vector<int>> res;
  vector<int> path;
  void dfs(int index, const vector<int>& nums) {
    if (index == nums.size()) {
      if (path.size() >= 2) res.push_back(path);
      return;
    }
    if (path.empty() || nums[index] >= path.back()) {
      path.push_back(nums[index]);
      dfs(index + 1, nums);
      path.pop_back();
    }
    if (index != 0 && !path.empty() && nums[index] == path.back()) return;
    dfs(index + 1, nums);
  }
  vector<vector<int>> findSubsequences(vector<int>& nums) {
    if (nums.size() <= 1) return {};
    dfs(0, nums);
    return res;
  }
};

// @lc code=end
