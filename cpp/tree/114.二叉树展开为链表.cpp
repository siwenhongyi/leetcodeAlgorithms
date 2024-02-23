/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  vector<TreeNode*> res;
  void dfs(TreeNode* r) {
    if (!r) return;
    res.push_back(r);
    dfs(r->left);
    dfs(r->right);
  }
  void flatten(TreeNode* root) {
    if (!root) return;
    dfs(root);
    int i = 0, n = res.size();
    while (i < n - 1) {
      res[i]->left = NULL;
      res[i]->right = res[i + 1];
      i++;
    }
    res[i]->left = res[i]->right = NULL;
  }
};
// @lc code=end
