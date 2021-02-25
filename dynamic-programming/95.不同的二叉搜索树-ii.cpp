/*
 * @lc app=leetcode.cn id=95 lang=cpp
 *
 * [95] 不同的二叉搜索树 II
 */
#include "head.h"
// @lc code=start
class Solution {
 public:
  vector<TreeNode*> dfs(int l, int r) {
    if (l >= r) return {nullptr};
    vector<TreeNode*> res;
    for (int i = l; i < r; i++) {
      auto left = dfs(l, i);
      auto right = dfs(i + 1, r);
      for (auto& it : left)
        for (auto& iter : right) {
          auto ans = new TreeNode(i);
          ans->left = it;
          ans->right = iter;
          res.push_back(ans);
        }
    }
    return res;
  }
  vector<TreeNode*> generateTrees(int n) { return dfs(1, n + 1); }
};
// @lc code=end
