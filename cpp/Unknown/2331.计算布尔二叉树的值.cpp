/*
 * @lc app=leetcode.cn id=2331 lang=cpp
 *
 * [2331] 计算布尔二叉树的值
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
  bool dfs(TreeNode* root) {
    if (root->left == nullptr) return root->val;
    bool l = dfs(root->left), r = dfs(root->right);
    return root->val == 2 ? l || r : l && r;
  }

 public:
  bool evaluateTree(TreeNode* root) { return dfs(root); }
};
// @lc code=end
