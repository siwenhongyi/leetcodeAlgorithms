/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
 */
#include "head.h"
// @lc code=start

class Solution {
 public:
  ListNode* removeNthFromEnd(ListNode* head, int k) {
    ListNode *res = nullptr, *t = head, *father = new ListNode(0);
    father->next = head;
    res = father;
    int x = 1;
    while (t && x != k) {
      t = t->next;
      x++;
    }
    while (t->next) {
      t = t->next;
      father = head;
      head = head->next;
    }
    father->next = head->next;
    delete head;
    father = res;
    res = res->next;
    delete father;
    return res;
  }
};
// @lc code=end
