/*
* @lc app=leetcode.cn id=979 lang=cpp
*
* [979] 在二叉树中分配硬币
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
private:
    int res;
    int dfs(TreeNode* root) {
        if(!root) return 0;
        int l = dfs(root->left),r=dfs(root->right);
        int t = l + r + root->val - 1;
        res += abs(t);
        return t;
    }
public:
    int distributeCoins(TreeNode* root) {
        res = 0;
        dfs(root);
        return res;
    }
};
// @lc code=end

