/*
* @lc app=leetcode.cn id=543 lang=cpp
*
* [543] 二叉树的直径
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
private:
	int res;
public:
	int  DFS(TreeNode *root) {
		if (!root)
			return 0;
		int l = DFS(root->left);
		int r = DFS(root->right);
		res = max(res,l+r);
		return max(l,r)+1;
	}
	int diameterOfBinaryTree(TreeNode* root) {
        res = 0;
		DFS(root);
		return res;
	}
}; 

// @lc code=end

