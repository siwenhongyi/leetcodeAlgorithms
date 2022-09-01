/*
 * @lc app=leetcode.cn id=655 lang=cpp
 *
 * [655] 输出二叉树
 */
#include <bits/stdc++.h>

#include "head.h"
using namespace std;
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
  using tpp = tuple<TreeNode*, int, int>;
  int get_deep(TreeNode*& root, int l = 0) {
    if (!root) return l;
    return max(get_deep(root->left, l + 1), get_deep(root->right, l + 1));
  }

 public:
  vector<vector<string>> printTree(TreeNode* root) {
    if (!root) return {};
    int h = get_deep(root) - 1;
    int m = h + 1;
    int n = pow(2, h + 1) - 1, offset;
    vector<vector<string>> res(m, vector<string>(n, ""));
    queue<tpp> q;
    q.push(tpp(root, 0, (n - 1) / 2));
    while (q.size()) {
      auto&& [node, r, c] = q.front();
      res[r][c] = to_string(node->val);
      offset = pow(2, h - r - 1);
      if (node->left) q.push(tpp(node->left, r + 1, c - offset));
      if (node->right) q.push(tpp(node->right, r + 1, c + offset));
      q.pop();
    }
    return res;
  }
};
// @lc code=end

int main() {
  /*
   * any test cases
   */
  vector<string> cases = {"[1,2,3,null,4,6,7,5,null,null,null,9,null]"};
  for (auto& it : cases) {
    /* code */
    auto root = stringToTreeNode(it);
    auto res = Solution().printTree(root);
    for (auto& it : res) {
      for (auto& iter : it) {
        cout << iter << ' ';
      }
      cout << endl;
    }
  }
  return 0;
}
