/*
* @lc app=leetcode.cn id=144 lang=cpp
*
* [144] 二叉树的前序遍历
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
	vector<int> res;
public:
	void pre(TreeNode * root) {
		if (!root)
			return;
		res.push_back(root->val);
		if (root->left)
			pre(root->left);
		if (root->right)
			pre(root->right);
	}
	vector<int> preorderTraversal(TreeNode* root) {
		pre(root);
		return res;
	}
};

// @lc code=end

