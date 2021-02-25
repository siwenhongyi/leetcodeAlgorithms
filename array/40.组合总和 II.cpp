/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 private:
  vector<vector<int>> res;
  vector<int> path;
  int n, target;
  void dfs(int index, const vector<int>& nums, int sum) {
    if (sum == target) {
      res.push_back(path);
      return;
    }
    if (index > n) return;
    int st = index;
    while (index < n && sum + nums[index] <= target) {
      if (index > st && nums[index] == nums[index - 1]) {
        index++;
        continue;
      }
      path.push_back(nums[index]);
      dfs(index + 1, nums, sum + nums[index]);
      path.pop_back();
      index++;
    }
  }

 public:
  vector<vector<int>> combinationSum2(vector<int>& candidates, int t) {
    if (candidates.empty() || t == 0) return {};
    n = candidates.size();
    target = t;
    path.reserve(n);
    sort(candidates.begin(), candidates.end());
    dfs(0, candidates, 0);
    return res;
  }
};
// @lc code=end
