/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */
#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 private:
  vector<int> path;
  vector<vector<int>> res;
  void dfs(const vector<int>& nums, int index, const int& target, int sum) {
    if (sum == target) res.emplace_back(path);
    if (sum >= target || index == nums.size()) return;

    // use
    path.emplace_back(nums[index]);
    dfs(nums, index, target, sum + nums[index]);
    // skip
    path.pop_back();
    dfs(nums, index + 1, target, sum);
  }

 public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    if (target == 0) return {};
    dfs(candidates, 0, target, 0);
    return res;
  }
};
// @lc code=end
