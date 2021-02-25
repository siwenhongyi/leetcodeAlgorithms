/*
* @lc app=leetcode.cn id=1008 lang=cpp
*
* [1008] 前序遍历构造二叉搜索树
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
    int n;
    vector<int> x;
    void dfs(TreeNode *&r,int index,int en){
        if(index>=en)
            return;
        r = new TreeNode(x[index]);
        int t = index+1;
        while(t<n&&x[t]<x[index])
            t++;
        if(t!=index+1)
            dfs(r->left,index+1,t);
        dfs(r->right,t,en);
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        n = preorder.size();
        if(!n)
            return NULL;
        x.swap(preorder);
        TreeNode *root = NULL;
        dfs(root,0,n);
        return root;
    }
};
// @lc code=end

