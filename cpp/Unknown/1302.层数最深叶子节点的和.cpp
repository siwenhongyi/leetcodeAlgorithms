/*
 * @lc app=leetcode.cn id=1302 lang=cpp
 *
 * [1302] 层数最深叶子节点的和
 */

#include "head.h"
using namespace std;
// @lc code=start
void clear(queue<TreeNode*>& p) {
  queue<TreeNode*> empty;
  p.swap(empty);
}
class Solution {
 public:
  int deepestLeavesSum(TreeNode* root) {
    if (!root) return 0;
    int ans = 0;
    queue<TreeNode*> p, q, res;
    p.push(root);
    while (p.size()) {
      while (p.size()) {
        auto qa = p.front();
        p.pop();
        res.push(qa);
        if (qa->left) q.push(qa->left);
        if (qa->right) q.push(qa->right);
      }
      if (q.empty()) {
        while (res.size()) {
          ans += res.front()->val;
          res.pop();
        }
        return ans;
      }
      p.swap(q);
      clear(res);
    }
    return 0;
  }
};
// @lc code=end
