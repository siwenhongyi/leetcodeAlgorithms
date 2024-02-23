/*
 * @lc app=leetcode.cn id=606 lang=cpp
 *
 * [606] 根据二叉树创建字符串
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
  string res;

 public:
  void dfs(TreeNode* root) {
    if (!root) {
      res += "()";
      return;
    }
    // res+='(' + '0'+root->val;
    res.push_back('(');
    res += to_string(root->val);
    bool a = root->left != NULL, b = root->right != NULL;
    if (a || b) {
      dfs(root->left);
      if (root->right) dfs(root->right);
    }
    res.push_back(')');
  }

  string tree2str(TreeNode* t) {
    dfs(t);
    return res.substr(1, res.size() - 2);
  }
};

// @lc code=end
