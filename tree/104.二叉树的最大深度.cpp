/*
* @lc app=leetcode.cn id=104 lang=cpp
*
* [104] 二叉树的最大深度
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
private:
	int m;
public:
	void DFS(TreeNode *root,int  h) {
		if (root->left == NULL && root->right == NULL) {
			if (h > m)
				m = h;
			return;
		}
		if (root->left != NULL)
			DFS(root->left, h + 1);
		if (root->right != NULL)
			DFS(root->right, h + 1);
	}
	int maxDepth(TreeNode* root) {
        if(root==NULL)
            return 0;
		if (root->left == NULL && root->right == NULL) 
			return 1;
		m = 0;
		DFS(root, 1);
        return m;
	}
};

// @lc code=end

