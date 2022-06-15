/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
  ListNode* mergeTwoLists(ListNode* s, ListNode* t) {
    if (!s || !t) return !s ? t : s;
    auto head = new ListNode(0);
    auto temp = head;
    while (s && t) {
      if (s->val < t->val) {
        temp->next = s;
        s = s->next;
      } else {
        temp->next = t;
        t = t->next;
      }
      temp = temp->next;
    }
    if (!s) temp->next = t;
    if (!t) temp->next = s;
    temp = head->next;
    delete head;
    return temp;
  }
};
// @lc code=end
