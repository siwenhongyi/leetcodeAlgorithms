/*
 * @lc app=leetcode.cn id=1145 lang=cpp
 *
 * [1145] 二叉树着色游戏
 */

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
  int node_num, target;
  bool is_find, res;
  int dfs(TreeNode* root) {
    if (!root) return 0;
    auto &&l = dfs(root->left), &&r = dfs(root->right);
    if (is_find) return 0;
    auto&& curr = l + r + 1;
    if (root->val != target) return curr;
    /*
    x将树分为了三个部分， 左子树、右子树、以及除了x树以外的
    任意一个部分的数量大于整体的一半，则选择就可以获胜
    */
    auto &&m = node_num - curr, &&ht = (node_num + 1) / 2;
    is_find = true;
    // if (m > curr || l > 1 + r + m || r > 1 + l + m) res = true;
    if (l >= ht || r >= ht || m >= ht) res = true;
    return 0;
  }

 public:
  bool btreeGameWinningMove(TreeNode* root, int n, int x) {
    res = is_find = false;
    node_num = n, target = x;
    dfs(root);
    return res;
  }
};
// @lc code=end
