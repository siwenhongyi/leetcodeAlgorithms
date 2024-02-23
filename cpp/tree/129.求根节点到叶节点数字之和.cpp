/*
 * @lc app=leetcode.cn id=129 lang=cpp
 *
 * [129] 求根节点到叶节点数字之和
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
  using us = unsigned int;
  us res;
  void sum(TreeNode* root, us s = 0) {
    if (root == nullptr) return;
    auto&& t = s * 10 + root->val;
    if (root->left == nullptr && root->right == nullptr) {
      res += t;
      return;
    }
    sum(root->left, t);
    sum(root->right, t);
    return;
  }

 public:
  int sumNumbers(TreeNode* root) {
    if (root == nullptr) return 0;
    res = 0;
    sum(root);
    return res;
  }
};
// @lc code=end
