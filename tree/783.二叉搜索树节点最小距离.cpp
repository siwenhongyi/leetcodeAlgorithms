/*
 * @lc app=leetcode.cn id=783 lang=cpp
 *
 * [783] 二叉搜索树节点最小距离
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  int d(TreeNode* root) {
    if (root->right) return d(root->right);
    return root->val;
  }
  int x(TreeNode* root) {
    if (root->left) return x(root->left);
    return root->val;
  }
  int minDiffInBST(TreeNode* root) {
    int res = (1 << 30) - 1;
    queue<TreeNode*> q;
    q.push(root);
    while (q.size()) {
      auto qa = q.front();
      q.pop();
      if (qa->left) {
        res = min(res, qa->val - d(qa->left));
        q.push(qa->left);
      }
      if (qa->right) {
        res = min(res, x(qa->right) - qa->val);
        q.push(qa->right);
      }
      if (res == 1) break;
    }
    return res;
  }
};

// @lc code=end
