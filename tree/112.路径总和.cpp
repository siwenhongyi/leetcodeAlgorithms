/*
* @lc app=leetcode.cn id=112 lang=cpp
*
* [112] 路径总和
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
public:
    int target;
    bool ans;
    void dfs(TreeNode* root, int x) {
        if (!root->left&&!root->right){
            ans = x + root->val == target;
            return;
        }
        if (root->left)
            dfs(root->left, x + root->val);
        if (ans)
            return;
        if (root->right)
            dfs(root->right, x + root->val);
    }
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root)
            return false;
        target = sum;
        ans = false;
        dfs(root,0 );
        return ans;
    }
};

// @lc code=end

