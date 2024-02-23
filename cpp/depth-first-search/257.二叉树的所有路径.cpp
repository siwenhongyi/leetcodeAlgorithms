/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
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
    vector<string> res;
    void dosm(vector<int>& path) {
        auto n = path.size();
        string s;
        for(auto i = (n-n);i<n;i++) {
            if(i) s += "->";
            s += to_string(path[i]);
        }
        res.push_back(s);
    }
    void dfs(TreeNode*& root,vector<int>& path) {
        if(root == nullptr)
            return;
        path.push_back(root->val);      
        if(!root->left&&!root->right){
            dosm(path);
            path.pop_back();
            return;
        }
        dfs(root->left,path);
        dfs(root->right,path);
        path.pop_back();
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int> path;
        dfs(root,path);
        return res;
    }
};
// @lc code=end

