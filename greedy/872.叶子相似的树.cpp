/*
 * @lc app=leetcode.cn id=872 lang=cpp
 *
 * [872] 叶子相似的树
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  vector<vector<int>> res;
  int index;
  void dfs(TreeNode* root) {
    if (!root) return;
    if (!root->left && !root->right)
      res[index].push_back(root->val);
    else {
      dfs(root->left);
      dfs(root->right);
    }
  }
  bool leafSimilar(TreeNode* root1, TreeNode* root2) {
    index = 0;
    res.resize(2);
    dfs(root1);
    index++;
    dfs(root2);

    return res[0] == res[1];
  }
};
// @lc code=end
