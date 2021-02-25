/*
* @lc app=leetcode.cn id=1022 lang=cpp
*
* [1022] 从根到叶的二进制数之和
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
	int res;
	string t;
public:
	void DFS(TreeNode * root) {
		t.push_back('0' + root->val);
		if (!root->left && !root->right) {
			ato();
			t.pop_back();
			return;
		}
		else {
			if (root->left)
				DFS(root->left);
			if (root->right)
				DFS(root->right);
			t.pop_back();
		}
	}
	void ato() {
		long long int x = 0;
		for (auto it = t.begin(); it != t.end(); it++)
			x = x * 2 + (*it - '0');
		res = (res + x % 1000000007) % 1000000007;
	}
	int sumRootToLeaf(TreeNode* root) {
		if (!root)
			return 0;
		res = 0;
		DFS(root);
		return res;
	}
};

// @lc code=end

