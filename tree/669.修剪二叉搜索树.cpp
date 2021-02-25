/*
* @lc app=leetcode.cn id=669 lang=cpp
*
* [669] 修剪二叉搜索树
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
private:
    int l, r;
    TreeNode* res;
public:
    TreeNode* dfs(TreeNode* root) {
        if (!root) return nullptr;
        if (root->val < l) root->left = nullptr;
        else root->left = dfs(root->left);
        if (root->val > r)
            root->right = nullptr;
        else root->right = dfs(root->right);
        if (root->val >= l && root->val <= r) return root;
        if (root->left) return root->left;
        return root->right;
    }
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (!root) return nullptr;
        if (root->val < low) return trimBST(root->right, low, high);
        if (root->val > high) return trimBST(root->left, low, high);
        l = low, r = high;
        root = dfs(root);
        return root;
    }
};
// @lc code=end

