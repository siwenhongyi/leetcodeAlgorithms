/*
* @lc app=leetcode.cn id=94 lang=cpp
*
* [94] 二叉树的中序遍历
*/

#include"head.h"
using namespace std;
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> res;
    void dfs(TreeNode*r){
        if(!r)
            return;
        if(r->left)
            dfs(r->left);
        res.push_back(r->val);
        if(r->right)
            dfs(r->right);
        
    }
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root)
            return res;
        dfs(root);
        return res;
    }
};
// @lc code=end

