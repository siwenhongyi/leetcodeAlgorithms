/*
 * @lc app=leetcode.cn id=429 lang=cpp
 *
 * [429] N 叉树的层序遍历
 */

#include "head.h"
using namespace std;
// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
 public:
  vector<vector<int>> levelOrder(Node* root) {
    if (!root) return {};
    vector<vector<int>> res;
    queue<Node*> p, q;
    q.push(root);
    while (q.size()) {
      vector<int> t;
      while (q.size()) {
        auto qa = q.front();
        q.pop();
        t.push_back(qa->val);
        for (auto& i : qa->children) p.push(i);
      }
      p.swap(q);
      res.push_back(t);
    }
    return res;
  }
};
// @lc code=end
