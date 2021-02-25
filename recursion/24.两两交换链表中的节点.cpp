/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 */
#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  ListNode* swapPairs(ListNode* head) {
    if (head == NULL || head->next == NULL) return head;
    ListNode *p = head, *q = head->next;
    ListNode f(-1);
    ListNode* re = &f;
    head = re;
    re->next = p;
    while (p && q) {
      re->next = q;
      p->next = q->next;
      q->next = p;
      re = p;
      p = p->next;
      if (p) q = p->next;
    }
    return head->next;
  }
};
// @lc code=end
