/*
 * @lc app=leetcode.cn id=563 lang=cpp
 *
 * [563] 二叉树的坡度
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
    int sum;
    int dfs(TreeNode*& root) {
        if(root == nullptr)
            return 0;
        auto l = dfs(root->left),r=dfs(root->right);
        sum += abs(l-r);
        return l + r + root->val;
    }
public:
    int findTilt(TreeNode* root) {
        sum = 0;
        dfs(root);
        return sum;
    }
};
// @lc code=end

