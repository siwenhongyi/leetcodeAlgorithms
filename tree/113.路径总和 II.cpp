/*
* @lc app=leetcode.cn id=113 lang=cpp
*
* [113] 路径总和 II
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    int need;
    void dfs(TreeNode* root,int sum) {
        path.push_back(root->val);
        sum += root->val;
        if (!root->left && !root->right) {
            if (sum == need)
                res.push_back(path);
        }
        else {
            if (root->left)
                dfs(root->left, sum);            
            if (root->right)
                dfs(root->right, sum);
        }
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if (!root)
            return {};
        need = sum;
        dfs(root, 0);
        return res;
    }
};

// @lc code=end

