/*
* @lc app=leetcode.cn id=100 lang=cpp
*
* [100] 相同的树
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
    bool dfs(TreeNode* &p, TreeNode* &q){
        bool x = p==NULL,y = q==NULL;
        if(x&&y)
            return true;
        if(x||y||p->val!=q->val)
            return false;
        x = dfs(p->left,q->left);
        y = dfs(p->right,q->right);
        return x&&y;
        
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return dfs(p,q);
    }
};
// @lc code=end

