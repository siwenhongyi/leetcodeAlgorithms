/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
 */

#include "head.h"
using namespace std;
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
 private:
  TreeNode* func(const vector<int>& nums, int x, int y) {
    if (x < 0 || x >= y) return nullptr;
    int index = x + (y - x) / 2;
    auto root = new TreeNode(nums[index]);
    root->left = func(nums, x, index);
    root->right = func(nums, index + 1, y);
    return root;
  }

 public:
  TreeNode* sortedArrayToBST(vector<int>& nums) {
    if (nums.empty()) return nullptr;
    return func(nums, 0, nums.size());
  }
};
// @lc code=end
