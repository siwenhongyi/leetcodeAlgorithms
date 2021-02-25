/*
 * @lc app=leetcode.cn id=1214 lang=cpp
 *
 * [1214] 查找两棵二叉搜索树之和
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  unordered_map<int, bool> a[2];
  int index;
  void dfs(TreeNode* s) {
    if (!s) return;
    a[index][s->val] = true;
    dfs(s->left);
    dfs(s->right);
  }
  bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
    index = 0;
    dfs(root1);
    index = 1;
    dfs(root2);
    for (auto& i : a[0]) {
      if (a[1][target - i.first]) return true;
    }
    return false;
  }
};
// @lc code=end
