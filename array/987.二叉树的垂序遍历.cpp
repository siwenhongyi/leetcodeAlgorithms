/*
 * @lc app=leetcode.cn id=987 lang=cpp
 *
 * [987] 二叉树的垂序遍历
 */
#include "head.h"
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
  using TII = tuple<TreeNode*, int, int>;
  struct cmp {
    bool operator()(const TII& s, const TII& t) {
      auto&& [root_xy, x, y] = s;
      auto&& [root_ab, a, b] = t;
      if (x == a) return root_xy->val > root_ab->val;
      return x > a;
    }
  };

 public:
  vector<vector<int>> verticalTraversal(TreeNode* root) {
    if (!root) return {};
    priority_queue<TII, vector<TII>, cmp> q;
    map<int, vector<int>> pos;
    vector<vector<int>> res;
    q.emplace(root, 0, 0);
    while (q.size()) {
      auto qa = q.top();
      q.pop();
      auto&& [root, x, y] = qa;
      pos[y].push_back(root->val);
      if (root->left) q.emplace(root->left, x + 1, y - 1);
      if (root->right) q.emplace(root->right, x + 1, y + 1);
    }
    for (auto& it : pos) res.push_back(it.second);
    return res;
  }
};
// @lc code=end
