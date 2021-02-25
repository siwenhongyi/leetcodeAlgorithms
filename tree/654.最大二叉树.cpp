/*
* @lc app=leetcode.cn id=654 lang=cpp
*
* [654] 最大二叉树
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
	 vector<int> pos;
 public:
	 TreeNode* insert(int st,int en) {
		 if (st > en)
			 return nullptr;
         int m = pos[st],index = st;
         for(int i = st+1;i<=en;i++){
             if(pos[i]>m){
                 m=pos[i];
                 index = i;
             }
         }
		 TreeNode* res = new TreeNode(pos[index]);
		 res->left = insert(st, index-1);
		 res->right = insert(index + 1, en);
		 return res;
	 }



	 TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
		 if (nums.empty())
			 return nullptr;
		 pos = nums;
		 TreeNode* root = insert(0, nums.size()-1);
		 return root;
	 }
 }; 

// @lc code=end

