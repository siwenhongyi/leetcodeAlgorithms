/*
 * @lc app=leetcode.cn id=951 lang=cpp
 *
 * [951] 翻转等价二叉树
 */

#include "head.h"
using namespace std;
class Solution {
 public:
  bool dfs(TreeNode* s, TreeNode* t) {
    if (s == NULL && t == NULL) return true;
    if ((s == NULL) || (t == NULL)) {
      return false;
    }
    if (s->val != t->val) {
      return false;
    }
    bool l = dfs(s->left, t->left) && dfs(s->right, t->right);
    bool r = dfs(s->left, t->right) && dfs(s->right, t->left);
    return l || r;
  }
  bool flipEquiv(TreeNode* root1, TreeNode* root2) { return dfs(root1, root2); }
};

// @lc code=end
