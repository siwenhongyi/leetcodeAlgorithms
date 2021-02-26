/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
 public:
  ListNode* addTwoNumbers(ListNode* s, ListNode* t) {
    ListNode *res = nullptr, *now = nullptr;
    int c, r;
    c = r = 0;
    while (s || t) {
      c = r;
      if (s) {
        c += s->val;
        s = s->next;
      }
      if (t) {
        c += t->val;
        t = t->next;
      }
      if (res) {
        now->next = new ListNode(c % 10);
        now = now->next;
      } else {
        res = now = new ListNode(c % 10);
      }
      r = c / 10;
    }
    if (r) now->next = new ListNode(r);
    return res;
  }
};
// @lc code=end
