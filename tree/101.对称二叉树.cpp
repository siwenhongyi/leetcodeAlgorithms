/*
* @lc app=leetcode.cn id=101 lang=cpp
*
* [101] 对称二叉树
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
    bool dfs(TreeNode* l,TreeNode* r){
        if(!l&&!r) return true;
        if(!r||!l) return false;
        return l->val == r->val && dfs(l->left,r->right)&&dfs(l->right,r->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return dfs(root->left,root->right);
    }
};
// @lc code=end

