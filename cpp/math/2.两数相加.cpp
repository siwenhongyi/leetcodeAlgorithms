/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
class Solution {
 public:
  ListNode* addTwoNumbers(ListNode* s, ListNode* t) {
    ListNode *head, *curr;
    head = curr = nullptr;
    int sum, r;
    sum = r = 0;
    while (s || t) {
      if (s) {
        sum += s->val;
        s = s->next;
      }
      if (t) {
        sum += t->val;
        t = t->next;
      }
      auto n = new ListNode(sum % 10);
      if (curr) {
        curr->next = n;
        curr = n;
      } else {
        head = curr = n;
      }
      sum /= 10;
    }
    if (sum) {
      auto n = new ListNode(sum % 10);
      curr->next = n;
    }
    return head;
  }
};
// @lc code=end
