/*
 * @lc app=leetcode.cn id=173 lang=cpp
 *
 * [173] 二叉搜索树迭代器
 */
#include "head.h"
using namespace std;
// @lc code=start
class BSTIterator {
 private:
  using PTI = pair<TreeNode*, int>;
  stack<PTI> q;

 public:
  BSTIterator(TreeNode* root) {
    if (root) q.emplace(root, 0);
  }
  /** @return the next smallest number */
  int next() {
    while (q.size()) {
      auto&& [root, type] = q.top();
      if (type == 0) {
        type = 1;
        if (root->left) q.push({root->left, 0});
      } else {
        TreeNode* temp = root;
        q.pop();
        if (temp->right) q.emplace(temp->right, 0);
        return temp->val;
      }
    }
    return -1;
  }
  /** @return whether we have a next smallest number */
  bool hasNext() { return !q.empty(); }
};
// @lc code=end
