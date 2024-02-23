/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> res;
    vector<int> pos;
    if (!root) return res;
    vector<TreeNode*> p, q;
    q.push_back(root);
    while (q.size()) {
      int n = q.size();
      while (n) {
        auto t = q[n - 1];
        // pop_back();
        pos.push_back(t->val);
        if (t->left) p.push_back(t->left);
        if (t->right) p.push_back(t->right);
        n--;
      }
      q.resize(p.size());
      reverse_copy(p.begin(), p.end(), q.begin());
      p.clear();
      res.push_back(pos);
      pos.clear();
    }
    return res;
  }
};

// @lc code=end
