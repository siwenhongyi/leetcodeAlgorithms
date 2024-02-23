/*
 * @lc app=leetcode.cn id=998 lang=cpp
 *
 * [998] 最大二叉树 II
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
  vector<int> tail;
  void dfs(TreeNode* root) {
    if (!root) return;
    if (root->left) {
      dfs(root->left);
      //   tail.push_back(root->left->val);
    }
    tail.push_back(root->val);

    if (root->right) {
      dfs(root->right);
      //   tail.push_back(root->right->val);
    }
  }
  TreeNode* build(int l, int r) {
    if (l >= r) return nullptr;
    auto m = max_element(tail.begin() + l, tail.begin() + r) - tail.begin();
    auto root = new TreeNode(tail[m]);
    root->left = build(l, m);
    root->right = build(m + 1, r);
    return root;
  }

 public:
  TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
    dfs(root);
    tail.push_back(val);
    auto res = build(0, tail.size());
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
