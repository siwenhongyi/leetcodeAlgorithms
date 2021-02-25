/*
* @lc app=leetcode.cn id=404 lang=cpp
*
* [404] 左叶子之和
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
    int res;
public:
    void dfs(TreeNode* root,int val = 0){
        if(!root)
            return;
        if(root->left==NULL&&root->right==NULL){
            if(val)
                res+=root->val;
            return ;
        }
        if(root->left)
            dfs(root->left,1);
        if(root->right)
            dfs(root->right);
        
    }
    int sumOfLeftLeaves(TreeNode* root) {
        res = 0;
        dfs(root);
        return res;
    }
};
// @lc code=end

