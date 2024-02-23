/*
 * @lc app=leetcode.cn id=1038 lang=cpp
 *
 * [1038] 把二叉搜索树转换为累加树
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
  int x;

 public:
  void dfs(TreeNode* s) {
    if (!s) return;
    dfs(s->right);
    x += s->val;
    s->val = x;
    dfs(s->left);
  }
  TreeNode* bstToGst(TreeNode* root) {
    if (!root) return root;
    x = 0;
    dfs(root);
    return root;
  }
};
// @lc code=end
