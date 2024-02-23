/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  ListNode* partition(ListNode* head, int x) {
    if (!head) return head;
    ListNode *p, *q, *t, *tt;
    p = q = t = tt = NULL;
    while (head) {
      if (head->val < x)
        if (p) {
          t->next = head;
          t = head;
        } else
          p = t = head;

      else if (q) {
        tt->next = head;
        tt = head;
      } else
        q = tt = head;
      head = head->next;
    }
    if (p) {
      t->next = q;
      if (tt) tt->next = NULL;
    } else
      p = q;
    return p;
  }
};
// @lc code=end
