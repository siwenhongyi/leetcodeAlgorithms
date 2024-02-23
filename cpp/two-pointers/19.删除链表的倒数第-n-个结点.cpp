/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
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
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    if (head == nullptr) return head;
    // fuck
    auto l = head, r = head;
    int cnt = 0;
    while (cnt != n) {
      r = r->next == nullptr ? head : r->next;
      cnt++;
    }
    if (r == l) return head->next;
    while (r->next) {
      r = r->next;
      l = l->next;
    }
    auto d = l->next;
    l->next = d->next;
    delete d;
    return head;
  }
};
// @lc code=end
