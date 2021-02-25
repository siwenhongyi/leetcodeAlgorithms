/*
* @lc app=leetcode.cn id=1161 lang=cpp
*
* [1161] 最大层内元素和
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
	void dfs(TreeNode * root,int h) {
		if (!root)
			return;
		if (h == res.size())
			res.push_back(root->val);
		else
			res[h] += root->val;
		dfs(root->left, h + 1);;
		dfs(root->right, h + 1);
	}
	int maxLevelSum(TreeNode* root) {
		dfs(root, 0);
		int m = 0, ans = 1;
		for (int i = 0; i < res.size(); i++) 
			if (res[i] > m) {
				m = res[i];
				ans = i+1;
			}
			
		return ans;
	}
};

// @lc code=end

