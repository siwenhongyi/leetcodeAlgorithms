/*
 * @lc app=leetcode.cn id=235 lang=cpp
 *
 * [235] 二叉搜索树的最近公共祖先
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root->val == p->val || root->val == q->val) return root;
    if (root->val < p->val && root->val < q->val)
      return lowestCommonAncestor(root->right, p, q);
    else if (root->val > p->val && root->val > q->val)
      return lowestCommonAncestor(root->left, p, q);
    else
      return root;
  }
};
// @lc code=end
