/*
 * @lc app=leetcode.cn id=814 lang=cpp
 *
 * [814] 二叉树剪枝
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  void dfs(TreeNode* r, TreeNode*& pre, int lr) {
    if (r->left) dfs(r->left, r, 1);
    if (r->right) dfs(r->right, r, 2);
    if (!r->left && !r->right && r->val == 0) {
      if (lr == 1)
        pre->left = NULL;
      else if (lr == 2)
        pre->right = NULL;
      delete r;
    }
  }
  TreeNode* pruneTree(TreeNode* root) {
    if (!root) return root;
    TreeNode* t = NULL;
    dfs(root, t, -1);
    return root;
  }
};
// @lc code=end
