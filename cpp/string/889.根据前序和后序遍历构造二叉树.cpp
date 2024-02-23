/*
 * @lc app=leetcode.cn id=889 lang=cpp
 *
 * [889] 根据前序和后序遍历构造二叉树
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 private:
  vector<int> pre, post;

 public:
  TreeNode* build(int st, int en, int postroot) {
    if (st > en) return NULL;
    TreeNode* root = new TreeNode(pre[st]);
    if (postroot <= 0 || st == en) return root;
    int rroot = post[postroot - 1], index;
    for (int i = st; i <= en; i++) {
      if (pre[i] == rroot) {
        index = i;
        break;
      }
    }
    root->right = build(index, en, postroot - 1);
    if (index == st + 1) {
      return root;
    }
    int lroot = pre[st + 1];
    for (int i = 0; i <= postroot; i++) {
      if (post[i] == lroot) {
        lroot = i;
        break;
      }
    }
    root->left = build(st + 1, index - 1, lroot);
    return root;
  }
  TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
    int n = post.size();
    this->pre.swap(pre);
    this->post.swap(post);
    TreeNode* root = build(0, n - 1, n - 1);
    return root;
  }
};

// @lc code=end
