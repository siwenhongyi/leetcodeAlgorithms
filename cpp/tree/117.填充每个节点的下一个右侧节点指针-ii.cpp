/*
 * @lc app=leetcode.cn id=117 lang=cpp
 *
 * [117] 填充每个节点的下一个右侧节点指针 II
 */

#include "head.h"
using namespace std;
// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
class Solution {
 public:
  Node* connect(Node* root) {
    if (root == nullptr) return root;
    queue<Node*> q;
    q.push(root);
    int l = 1;
    while (l) {
      while (l--) {
        auto qa = q.front();
        q.pop();
        if (l) qa->next = q.front();
        if (qa->left) q.push(qa->left);
        if (qa->right) q.push(qa->right);
      }
      l = q.size();
    }
    return root;
  }
};
// @lc code=end
