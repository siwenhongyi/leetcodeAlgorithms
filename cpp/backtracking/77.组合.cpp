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
  vector<int> path;
  void dfs(int st, const int& n, const int& k) {
    if (path.size() + n - st + 1 < k) return;
    if (path.size() == k) {
      res.push_back(path);
      return;
    }
    path.push_back(st);
    dfs(st + 1, n, k);
    path.pop_back();
    dfs(st + 1, n, k);
    return;
  }

 public:
  vector<vector<int>> combine(int n, int k) {
    dfs(1, n, k);
    return res;
  }
};
// @lc code=end
