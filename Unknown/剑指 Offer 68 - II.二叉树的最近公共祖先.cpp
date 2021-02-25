/*
 * @lc app=leetcode.cn id=剑指 Offer 68 - II lang=cpp
 *
 * [剑指 Offer 68 - II] 二叉树的最近公共祖先
 */
#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  TreeNode* ans;
  TreeNode *pp, *qq;
  bool dfs(TreeNode* root) {
    if (!root) return false;
    bool now = root == pp || root == qq;
    bool left = dfs(root->left);
    bool right = dfs(root->right);
    if (now && left + right == 1) {
      ans = root;
    } else if (!now && left && right) {
      ans = root;
    }
    return now || left || right;
  }
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root) return nullptr;
    ans = nullptr;
    pp = p, qq = q;
    dfs(root);
    return ans;
  }
};
// @lc code=end
