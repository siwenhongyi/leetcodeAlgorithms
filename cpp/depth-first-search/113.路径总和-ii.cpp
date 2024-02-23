/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
 */
#include "head.h"
using namesapce std;
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
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(root,sum,res,path);
        return res;
    }
    void dfs(TreeNode* root, int sum, vector<vector<int>>& res, vector<int>& path) {
        if(!root) return;
        path.push_back(root->val);
        if(!root->left&&!root->right&&root->val==sum) {
            res.push_back(path);
        }
        dfs(root->left,sum-root->val,res,path);
        dfs(root->right,sum-root->val,res,path);
        path.pop_back();
    }
    
};
// @lc code=end

