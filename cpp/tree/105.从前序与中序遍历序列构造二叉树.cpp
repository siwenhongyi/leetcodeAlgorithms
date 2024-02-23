/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
  using pii = pair<int, int>;
  unordered_map<int, int> m;
  TreeNode* build(vector<int>& pre, vector<int>& in, int pl, int pr, int il,
                  int ir) {
    if (pl >= pr) return nullptr;
    auto&& head_val = pre[pl];
    TreeNode* root = new TreeNode(head_val);
    int index = m[head_val];
    auto &&l_length = index - il, &&r_length = ir - index;
    root->left = build(pre, in, pl + 1, pl + l_length + 1, il, index);
    root->right = build(pre, in, pl + l_length + 1, pr, index + 1, ir);
    return root;
  }

 public:
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    if (preorder.empty()) return nullptr;
    int index = 0;
    for (const auto& it : inorder) {
      m[it] = index++;
    }
    return build(preorder, inorder, 0, preorder.size(), 0, inorder.size());
  }
};
// @lc code=end
