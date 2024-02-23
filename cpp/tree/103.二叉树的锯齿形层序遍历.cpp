/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层序遍历
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
 public:
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    if (root == nullptr) return {};
    vector res(0, vector(0, 0));
    stack<TreeNode*> s, t;
    s.push(root);
    while (s.size()) {
      vector path(0, 0);
      while (s.size()) {
        auto&& qa = s.top();
        // s.pop();
        path.push_back(qa->val);
        if (qa->left) t.push(qa->left);
        if (qa->right) t.push(qa->right);
        s.pop();
      }
      res.emplace_back(path);
      path.clear();
      while (t.size()) {
        auto&& qa = t.top();
        // t.pop();
        path.push_back(qa->val);
        if (qa->right) s.push(qa->right);
        if (qa->left) s.push(qa->left);
        t.pop();
      }
      if (path.size()) res.emplace_back(path);
    }
    return res;
  }
};
// @lc code=end
