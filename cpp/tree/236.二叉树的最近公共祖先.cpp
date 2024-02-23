/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
  int xx, yy;
  TreeNode* res;

 public:
  bool dfs(TreeNode* root) {
    if (!root) return false;
    bool t = (root->val == xx || root->val == yy);
    bool l = dfs(root->left);
    bool r = dfs(root->right);
    if (t + l + r >= 2) res = root;
    return (l || r || t);
  }
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    xx = p->val;
    yy = q->val;
    dfs(root);
    return res;
  }
};
// @lc code=end
