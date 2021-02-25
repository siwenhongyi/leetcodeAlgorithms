/*
 * @lc app=leetcode.cn id=1110 lang=cpp
 *
 * [1110] 删点成林
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 private:
  unordered_map<int, int> book;
  vector<TreeNode*> res;

 public:
  void dt(TreeNode* root) {
    if (!root) return;
    if (root->left || root->right) {
      dt(root->left);
      dt(root->right);
    }

    if (root->left && book[root->left->val]) {
      if (root->left->left) res.push_back(root->left->left);
      if (root->left->right) res.push_back(root->left->right);
      root->left = NULL;
    }

    if (root->right && book[root->right->val]) {
      if (root->right->left) res.push_back(root->right->left);
      if (root->right->right) res.push_back(root->right->right);
      root->right = NULL;
    }
  }
  vector<TreeNode*> delNodes(TreeNode* root, vector<int>& v) {
    if (!v.size()) return res;
    for (auto& i : v) book[i] = 1;
    dt(root);
    if (!book[root->val])
      res.push_back(root);
    else {
      if (root->left) res.push_back(root->left);
      if (root->right) res.push_back(root->right);
      root = NULL;
    }
    return res;
  }
};

// @lc code=end
