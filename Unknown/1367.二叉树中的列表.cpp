/*
 * @lc app=leetcode.cn id=1367 lang=cpp
 *
 * [1367] 二叉树中的列表
 */
#include "head.h"
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
 private:
  bool res;
  bool check(TreeNode*& root, ListNode*& head) {
    if (!head) return true;
    return (root) && (root->val == head->val) &&
           (check(root->left, head->next) || check(root->right, head->next));
  }
  void dfs(TreeNode*& root, ListNode*& head) {
    if (!root) return;
    if (root->val == head->val) {
      res = check(root, head);
    }
    if (!res) {
      dfs(root->left, head);
      if (!res) dfs(root->right, head);
    }
  }

 public:
  bool isSubPath(ListNode* head, TreeNode* root) {
    res = false;
    dfs(root, head);
    return res;
  }
};
// @lc code=end
