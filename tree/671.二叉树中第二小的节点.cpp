/*
 * @lc app=leetcode.cn id=671 lang=cpp
 *
 * [671] 二叉树中第二小的节点
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 private:
  set<int> res;

 public:
  void fun(TreeNode* root) {
    if (!root) return;
    res.insert(root->val);
    if (root->left) fun(root->left);
    if (root->right) fun(root->right);
  }
  int findSecondMinimumValue(TreeNode* root) {
    if (!root) return -1;
    fun(root);
    if (res.size() < 2) return -1;
    auto it = res.begin();
    return *(++it);
  }
};

// @lc code=end
