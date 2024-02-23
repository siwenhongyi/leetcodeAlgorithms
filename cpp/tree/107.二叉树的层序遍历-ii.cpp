/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层序遍历 II
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
  vector<vector<int>> levelOrderBottom(TreeNode* root) {
    if (root == nullptr) return {};
    queue<TreeNode*> q;
    vector<vector<int>> res;
    vector<int> tmp;
    q.push(root);
    while (q.size()) {
      tmp.clear();
      int l = q.size();
      while (l--) {
        auto qa = q.front();
        q.pop();
        tmp.emplace_back(qa->val);
        if (qa->left) q.push(qa->left);
        if (qa->right) q.push(qa->right);
      }
      res.emplace_back(tmp);
    }
    reverse(res.begin(), res.end());
    return res;
  }
};
// @lc code=end
