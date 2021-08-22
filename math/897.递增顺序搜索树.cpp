/*
 * @lc app=leetcode.cn id=897 lang=cpp
 *
 * [897] 递增顺序搜索树
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
public:
    TreeNode* increasingBST(TreeNode* root) {
        stack<TreeNode*> q;
        q.push(root);
        TreeNode* res,*head,*temp;
        res=head=temp = nullptr;
        while(q.size()) {
            auto qa = q.top();
            if(qa->left) {
                while(qa->left){
                    q.push(qa->left);
                    temp = qa;
                    qa = qa->left;
                    temp->left=nullptr;
                }
                continue;
            }
            q.pop();
            if(res == nullptr) 
                res = head = qa;
             else {
                 head->right = qa;
                 head = head->right;
             }
            if(qa->right)
                q.push(qa->right);
        }
        return res;
    }
};
// @lc code=end

