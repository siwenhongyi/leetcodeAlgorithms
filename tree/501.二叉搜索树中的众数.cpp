/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 private:
  int cou;
  map<int, int> book;
  vector<int> res;

 public:
  void dfs(TreeNode* root) {
    if (!root) return;
    if (++book[root->val] > cou) {
      cou = book[root->val];
      res.clear();
      res.push_back(root->val);
    } else if (book[root->val] == cou)
      res.push_back(root->val);
    dfs(root->left);
    dfs(root->right);
  }
  vector<int> findMode(TreeNode* root) {
    if (!root) return {};
    cou = 0;
    dfs(root);
    return res;
  }
};

// @lc code=end
