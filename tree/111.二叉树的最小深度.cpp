/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
    int res = (1<<30);
    void dfs(TreeNode* root,int deep) {
        if(!root || deep >= res)
            return;
        if(!root->left&&!root->right)
            res = min(res,deep);
        if(root->left)dfs(root->left,deep + 1);
        if(root->right)dfs(root->right,deep + 1);
    }
public:
    int minDepth(TreeNode* root) {
        if(root == nullptr)
            return 0;
        dfs(root,1);
        return res;
    }
};

// @lc code=end

