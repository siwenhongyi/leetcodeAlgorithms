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
  int len;
  vector<vector<int>> res;
  vector<int> path, num;

 public:
  void dfs(int lenth, int pre) {
    if (lenth < 0) return;
    if (lenth == 0) res.push_back(path);
    for (int i = 0; i < num.size(); i++)
      if (num[i] >= pre) {
        path.push_back(num[i]);
        dfs(lenth - num[i], num[i]);
        path.pop_back();
      }
  }
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    len = target;
    sort(candidates.begin(), candidates.end());
    candidates.erase(unique(candidates.begin(), candidates.end()),
                     candidates.end());
    num = candidates;
    dfs(target, -1);
    return res;
  }
};

// @lc code=end
