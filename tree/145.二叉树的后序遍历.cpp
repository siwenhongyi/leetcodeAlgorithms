/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
vector<int> pos;
public:
    void dfs(TreeNode*& root) {
        if(root == nullptr)
            return;
        dfs(root->left);
        dfs(root->right);
        pos.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        dfs(root);
        return pos;
    }
};
// @lc code=end

