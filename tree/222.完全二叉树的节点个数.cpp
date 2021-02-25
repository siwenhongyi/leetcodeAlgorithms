/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  int countNodes(TreeNode* root) {
    if (!root) return 0;
    int res = 0;
    queue<TreeNode*> q;
    TreeNode* qa;
    q.push(root);
    while (q.size()) {
      qa = q.front();
      q.pop();
      res++;
      if (qa->left) q.push(qa->left);
      if (qa->right) q.push(qa->right);
    }
    return res;
  }
};

// @lc code=end
