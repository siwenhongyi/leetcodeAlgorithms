/*
 * @lc app=leetcode.cn id=652 lang=cpp
 *
 * [652] 寻找重复的子树
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
  unordered_map<string, int> df_tree;
  vector<TreeNode*> res;
  string dfs(TreeNode* root) {
    if (!root) return " ";
    string curr(to_string(root->val));
    curr += ".";
    curr += dfs(root->left);
    curr += dfs(root->right);
    if (++df_tree[curr] == 2) res.emplace_back(root);
    return curr;
  }

 public:
  vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
    dfs(root);
    return res;
  }
};
// @lc code=end

int main() {
  /*
   * any test cases
   */
  return 0;
}
