/*
* @lc app=leetcode.cn id=1315 lang=cpp
*
* [1315] 祖父节点值为偶数的节点和
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
    int res;
    void dfs(TreeNode* root){
        if(!root)
            return;
        if(root->left){
            if(root->val%2==0)add(root->left);
            dfs(root->left);
        }
        if(root->right){
            if(root->val%2==0)add(root->right);
            dfs(root->right);
        }
    }
    void add(TreeNode* root){
        if(root->left)
            res += root->left->val;
        if(root->right)
            res+=root->right->val;
    }
    int sumEvenGrandparent(TreeNode* root) {
        res = 0;
        if(!root)
            return res;
        dfs(root);
        return res;
    }
};
// @lc code=end

