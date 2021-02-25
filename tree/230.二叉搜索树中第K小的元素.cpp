/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第K小的元素
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 private:
  int res, cou, k;
  bool b;

 public:
  void inorder(TreeNode* root) {
    if (!root) return;
    if (root->left) inorder(root->left);
    if (b) return;
    if (++cou == k) {
      res = root->val;
      b = true;
      return;
    }
    if (root->right) inorder(root->right);
  }
  int kthSmallest(TreeNode* root, int k) {
    b = cou = 0;
    res = -1;
    this->k = k;
    inorder(root);
    return res;
  }
};

// @lc code=end
