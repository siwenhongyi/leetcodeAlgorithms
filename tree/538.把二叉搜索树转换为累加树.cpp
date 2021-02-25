/*
* @lc app=leetcode.cn id=538 lang=cpp
*
* [538] 把二叉搜索树转换为累加树
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
public:
	void dfs(TreeNode* root,int &val) {
		if (!root)
			return;
		dfs(root->right, val);
		root->val += val;
		val = root->val;
		dfs(root->left, val);
	}
	TreeNode* convertBST(TreeNode* root) {
		if (!root)
			return root;
		int val = 0;
		dfs(root, val);
		return root;
	}
};
// @lc code=end

