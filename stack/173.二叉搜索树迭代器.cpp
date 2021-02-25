/*
* @lc app=leetcode.cn id=173 lang=cpp
*
* [173] 二叉搜索树迭代器
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
class BSTIterator {
public:
    vector<int> x;
    int index,n;
    void dfs(TreeNode *r){
        if(!r)
            return;
        if(r->left)
            dfs(r->left);
        x.push_back(r->val);
        if(r->right)
            dfs(r->right);
    }
    BSTIterator(TreeNode* root) {
        dfs(root);
        index = 0;
        n = x.size();
    }
    
    /** @return the next smallest number */
    int next() {
        return x[index++];
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return index<n;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end

