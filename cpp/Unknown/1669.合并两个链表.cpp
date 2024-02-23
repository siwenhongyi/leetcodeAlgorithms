/*
 * @lc app=leetcode.cn id=1669 lang=cpp
 *
 * [1669] 合并两个链表
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
  ListNode* mergeInBetween(ListNode* s, int a, int b, ListNode* t) {
    int index = 0;
    ListNode *a_pre, *b_next, *temp, *head = s;
    while (a + b) {
      if (index + 1 == a) {
        a_pre = head;
        a = 0;
      }
      if (index - 1 == b) {
        b_next = head;
        b = 0;
      }
      head = head->next;
      index++;
    }

    head = t;
    while (head->next) head = head->next;
    head->next = b_next;
    {
      head = a_pre->next;
      while (head != b_next) {
        temp = head;
        head = head->next;
        delete temp;
      }
    }
    a_pre->next = t;
    return s;
  }
};
// @lc code=end
