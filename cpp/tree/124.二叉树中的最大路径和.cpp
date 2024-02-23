/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
 */

#include "head.h"
using namespace std;
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
 private:
  int res;
  int dfs(TreeNode* root) {
    if (root == nullptr) return 0;
    auto &&l = dfs(root->left), &&r = dfs(root->right);
    res = max(res, l + r + root->val);
    res = max(res, max(l, r) + root->val);
    res = max(res, root->val);
    return max(root->val, root->val + max(l, r));
  }

 public:
  int maxPathSum(TreeNode* root) {
    if (root == nullptr) return 0;
    res = root->val;
    dfs(root);
    return res;
  }
};
// @lc code=end
