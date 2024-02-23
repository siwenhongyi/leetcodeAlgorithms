/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
  vector<vector<int>> res;
  vector<int> path, x;
  int n;

 public:
  void dfs(int index) {
    if (index == n) {
      res.push_back(path);
      return;
    }
    path.push_back(x[index]);
    dfs(index + 1);
    path.pop_back();
    dfs(index + 1);
  }
  vector<vector<int>> subsets(vector<int>& nums) {
    x.swap(nums);
    n = x.size();
    dfs(0);
    return res;
  }
};
// @lc code=end
