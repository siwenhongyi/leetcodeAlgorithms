/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 private:
  vector<vector<int>> res;
  void dfs(vector<int>& path, int st, const int& n, const int& k) {
    if (path.size() == k) {
      res.push_back(path);
      return;
    }
    if (k - path.size() <= n - st) dfs(path, st + 1, n, k);
    path.push_back(st);
    dfs(path, st + 1, n, k);
    path.pop_back();
    return;
  }

 public:
  vector<vector<int>> combine(int n, int k) {
    vector<int> path;
    dfs(path, 1, n, k);
    return res;
  }
};
// @lc code=end
