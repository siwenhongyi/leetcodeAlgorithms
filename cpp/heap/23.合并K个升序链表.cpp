/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
 */
#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    int s = lists.size();
    //删除空元素
    //定义迭代器
    // auto iter = lists.begin();
    vector<ListNode*>::iterator iter = lists.begin();
    while (iter != lists.end()) {
      if (!*iter)
        iter = lists.erase(iter);
      else
        iter++;
    }
    if (lists.empty()) return NULL;
    if (lists.size() == 1) return lists[0];
    iter = lists.begin();
    // head 组合后的头结点  p 新链表当前节点 q 待排序链表的节点 p
    // re新链表当前节点前一个节点
    ListNode *re, *head, *q, *p, *t;
    head = *iter;
    iter++;
    for (; iter != lists.end(); iter++) {
      re = p = head;
      q = *iter;
      while (p && q) {
        if (q->val <= p->val)
          if (p == head) {
            head = q;
            q = q->next;
            head->next = p;
            re = head;
            continue;
          } else {
            t = q;
            q = q->next;
            re->next = t;
            t->next = p;
            re = t;
            continue;
          }
        re = p;
        p = p->next;
      }
      if (q) re->next = q;
    }
    return head;
  }
};
// @lc code=end
