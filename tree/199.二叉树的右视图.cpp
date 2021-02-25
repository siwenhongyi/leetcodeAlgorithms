/*
* @lc app=leetcode.cn id=199 lang=cpp
*
* [199] 二叉树的右视图
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
	int h;
public:
	void DFS(TreeNode* root, int x) {
		if (x > h){
			res.push_back(root->val);
		    h++;
        }
		if (root->right)
			DFS(root->right, x + 1);
		if (root->left)
			DFS(root->left, x + 1);
	}
	vector<int> rightSideView(TreeNode* root) {
		if (root == NULL)
			return {};
		h = 0;
		DFS(root, 1);
		return res;
	}
};

// @lc code=end

