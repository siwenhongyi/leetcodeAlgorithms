/*
* @lc app=leetcode.cn id=637 lang=cpp
*
* [637] 二叉树的层平均值
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
    vector<double> averageOfLevels(TreeNode* root) {
        if(!root)
        return {};
        vector<double> res;
        queue<TreeNode*> q;
        q.push(root);
        int size_t,cou;
        long long sum;
        while(q.size()){
            cou = size_t = q.size();
            sum = 0;
            while(size_t--){
                auto qa = q.front();
                q.pop();
                sum += qa->val;
                if(qa->left)
                q.push(qa->left);
                if(qa->right)
                q.push(qa->right);
            }
            res.push_back(sum/double(cou));
        }
        return res;
    }
};
// @lc code=end

