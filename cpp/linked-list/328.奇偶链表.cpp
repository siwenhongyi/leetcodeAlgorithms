/*
 * @lc app=leetcode.cn id=328 lang=cpp
 *
 * [328] 奇偶链表
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  ListNode* oddEvenList(ListNode* head) {
    if (!head || !head->next || !head->next->next) return head;
    ListNode *o = head, *e = head->next, *p, *q, *t;
    while (e && e->next) {
      p = e->next;
      q = p->next;
      t = o->next;
      o->next = p;
      p->next = t;
      e->next = q;
      o = o->next;
      e = e->next;
    }
    return head;
  }
};

// @lc code=end
