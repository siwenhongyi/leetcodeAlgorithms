/*
 * @lc app=leetcode.cn id=1325 lang=cpp
 *
 * [1325] 删除给定值的叶子节点
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  int x;
  TreeNode* delete_leaf(TreeNode* root) {
    if (root == nullptr) return root;
    if (root->left) root->left = delete_leaf(root->left);
    if (root->right) root->right = delete_leaf(root->right);
    if (root && root->val == x && !root->left && !root->right) {
      // delete  root;
      return nullptr;
    }
    return root;
  }
  TreeNode* removeLeafNodes(TreeNode* root, int target) {
    if (!root) return root;
    x = target;
    root = delete_leaf(root);
    // delete_leaf(root->right);
    return root;
  }
};

// @lc code=end
