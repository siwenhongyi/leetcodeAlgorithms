/*
 * @lc app=leetcode.cn id=237 lang=cpp
 *
 * [237] 删除链表中的节点
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  void deleteNode(ListNode* node) {
    node->val = node->next->val;
    auto p = node->next;
    node->next = p->next;
    delete p;
  }
};
// @lc code=end
