/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
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
private:
int greater(TreeNode*& root) {
    if(root->right)
        return greater(root->right);
    return root->val;
}
int less(TreeNode*& root) {
    if(root->left)
        return less(root->left);
    return root->val;
}
public:
    int getMinimumDifference(TreeNode* root) {
        int res = (1<<30);
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()) {
            auto qa = q.front();
            q.pop();
            if(qa->left) {
                res = min(res,qa->val - greater(qa->left));
                q.push(qa->left);
            }
            if(qa->right){
                res = min(res,less(qa->right) - qa->val);
                q.push(qa->right);
            }
            if(res <= 1)
                break;
        }
        return res;
    }
};
// @lc code=end

