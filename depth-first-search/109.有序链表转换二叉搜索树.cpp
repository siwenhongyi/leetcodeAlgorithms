/*
 * @lc app=leetcode.cn id=109 lang=cpp
 *
 * [109] 有序链表转换二叉搜索树
 */

#include "head.h"
using namespace std;
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
class AvlTree {
 private:
  TreeNode* root;
  TreeNode* insert(TreeNode* root, int val) {
    if (root == nullptr) {
      root = new TreeNode(val);
      return root;
    }
    auto curr = root;
    stack<TreeNode*> st;
    while (curr) {
      st.push(curr);
      if (val < curr->val) {
        if (curr->left == nullptr) {
          curr->left = new TreeNode(val);
          break;
        } else {
          curr = curr->left;
        }
      } else {
        if (curr->right == nullptr) {
          curr->right = new TreeNode(val);
          break;
        } else {
          curr = curr->right;
        }
      }
    }
    while (st.size()) {
      curr = st.top();
      st.pop();
      int l = get_deepth(curr->left), r = get_deepth(curr->right);
      if (abs(l - r) > 1) {
        if (l > r) {
          curr = right_rotate(curr);
        } else {
          curr = left_rotate(curr);
        }
        if (st.empty()) {
          root = curr;
        } else {
          if (st.top()->left == curr) {
            st.top()->left = curr;
          } else {
            st.top()->right = curr;
          }
        }
        break;
      }
    }
    return root;
  }
  int get_deepth(TreeNode* root) {
    if (root == nullptr) {
      return 0;
    }
    return max(get_deepth(root->left), get_deepth(root->right)) + 1;
  }
  TreeNode* right_rotate(TreeNode* root) {
    TreeNode* l = root->left;
    TreeNode* lr = l->right;
    l->right = root;
    root->left = lr;
    return l;
  }
  TreeNode* left_rotate(TreeNode* root) {
    TreeNode* r = root->right;
    TreeNode* rl = r->left;
    r->left = root;
    root->right = rl;
    return r;
  }
  TreeNode* right_left_rotate(TreeNode* root) {
    root->right = right_rotate(root->right);
    return left_rotate(root);
  }
  TreeNode* left_right_rotate(TreeNode* root) {
    root->left = left_rotate(root->left);
    return right_rotate(root);
  }

 public:
  AvlTree() : root(nullptr) {}
  void insert(int val) { root = insert(root, val); }
  inline TreeNode* get_root() { return root; }
};

class Solution {
 public:
  TreeNode* sortedListToBST(ListNode* head) {
    if (head == nullptr) {
      return nullptr;
    }
    AvlTree avl;
    ListNode* p = head;
    while (p != nullptr) {
      avl.insert(p->val);
      p = p->next;
    }
    return avl.get_root();
  }
};
// @lc code=end
