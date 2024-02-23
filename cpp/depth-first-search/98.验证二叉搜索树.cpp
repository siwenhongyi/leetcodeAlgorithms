/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
    using tp = tuple<int,int,bool>;
private:
int p = INT_MIN+1;
public:
    tp dfs(TreeNode* root) {
        if(root == nullptr){
            return{p,p,true};
        }
        auto&& [la,li,lres] = dfs(root->left);
        // left childtree is not a search tree
        if(lres == false)
            return {p,p,false};
        auto&& [ra,ri,rres] = dfs(root->right);
        // right childtree is not a search tree
        if(rres == false)
            return {p,p,false};
        // left childtree have node->val greater than root->val
        if(la != p&&la>=root->val)
            return {p,p,false};
        // left childtree have node->val greater than root->val
        if(ri!=p&&ri<=root->val)
            return {p,p,false};
        // ok
        int a,i,res=true;
        a=i=root->val;
        if(la!=p)
            a = max(a,la);
        if(ra!=p)
            a = max(a,ra);
        if(li!=p)
            i = min(i,li);
        if(ri!=p)
            i = min(i,ri);
        return {a,i,res};
    }

    bool isValidBST(TreeNode* root) {
        if(root == nullptr)
            return true;
        auto&& [i,j,res] = dfs(root);
        return res;
    }
};
// @lc code=end

