/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
 */
#include "head.h"
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
class Solution {
 private:
  ListNode* __reverse(ListNode*& head) {
    auto first = new ListNode(0);
    auto second = head;
    first->next = second;
    while (second->next) {
      auto t = second->next;
      auto last = t->next;
      auto h = first->next;
      first->next = t;
      t->next = h;
      second->next = last;
    }
    second = first->next;
    delete first;
    return second;
  }

 public:
  ListNode* reverseBetween(ListNode* head, int left, int right) {
    if (right - left < 1) return head;
    auto res = new ListNode(0);
    res->next = head;
    head = res;
    ListNode *a, *b;
    int index = 0;
    while (index <= right) {
      if (index + 1 == left)
        a = head;
      else if (index == right)
        b = head;
      head = head->next;
      index++;
    }
    // auto second = b->next;
    b->next = nullptr;
    auto x = __reverse(a->next);
    a->next = x;
    while (x->next) x = x->next;
    x->next = head;
    head = res->next;
    delete res;
    return head;
  }
};
// @lc code=end
