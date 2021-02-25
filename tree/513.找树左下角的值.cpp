/*
 * @lc app=leetcode.cn id=513 lang=cpp
 *
 * [513] 找树左下角的值
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  int res, m;
  void dfs(TreeNode* r, int le) {
    if (!r) return;
    if (le > m) {
      m = le;
      res = r->val;
    }
    dfs(r->left, le + 1);
    dfs(r->right, le + 1);
  }
  int findBottomLeftValue(TreeNode* root) {
    m = 0;
    dfs(root, 1);
    return res;
  }
};
// @lc code=end
