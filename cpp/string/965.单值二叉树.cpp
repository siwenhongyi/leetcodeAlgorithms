/*
 * @lc app=leetcode.cn id=965 lang=cpp
 *
 * [965] 单值二叉树
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int tar;
    bool dfs(TreeNode*& root) {
        return (root == nullptr)||(root->val == tar&&dfs(root->left)&&dfs(root->right));
    }
public:
    bool isUnivalTree(TreeNode* root) {
        tar = root->val;
        return dfs(root);
    }
};
// @lc code=end

