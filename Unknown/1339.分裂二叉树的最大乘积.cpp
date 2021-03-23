/*
 * @lc app=leetcode.cn id=1339 lang=cpp
 *
 * [1339] 分裂二叉树的最大乘积
 */
#include "head.h"
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
 private:
  using ll = long long;
  int sum;
  ll res;
  static const int mod = 1e9 + 7;
  void getsum(TreeNode*& root) {
    if (!root) return;
    sum += root->val;
    getsum(root->left);
    getsum(root->right);
  }
  int getmax(TreeNode*& root) {
    if (!root) return 0;
    int l = getmax(root->left), r = getmax(root->right);
    int subsum = l + r + root->val;
    res = max(res, ll(sum - subsum) * subsum);
    return subsum;
  }

 public:
  int maxProduct(TreeNode* root) {
    sum = res = 0;
    getsum(root);
    getmax(root);
    return res % mod;
  }
};
// @lc code=end
