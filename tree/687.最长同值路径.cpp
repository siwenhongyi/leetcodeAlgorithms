/*
 * @lc app=leetcode.cn id=687 lang=cpp
 *
 * [687] 最长同值路径
 */
#include <bits/stdc++.h>

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
  int res;
  int dfs(TreeNode* root) {
    if (!root) return 0;
    if (!root->left && !root->right) return 0;
    int temp = 0;
    auto &&l = dfs(root->left), &&r = dfs(root->right);
    // res = max(res, max(l, r));
    if (root->left && root->val == root->left->val) {
      temp += l + 1;
    }
    if (root->right && root->val == root->right->val) {
      temp += r + 1;
    }
    res = max(res, temp);
    if (root->left && root->right && root->left->val == root->right->val &&
        root->val == root->left->val) {
      temp = max(l, r) + 1;
    }
    return temp;
  }

 public:
  int longestUnivaluePath(TreeNode* root) {
    res = 0;
    res = max(res, dfs(root));
    return res;
  }
};
// @lc code=end

int main() {
  /*
   * any test cases
   */
  return 0;
}
