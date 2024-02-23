/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
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
 private:
  struct cmp {
    bool operator()(const ListNode* s, const ListNode* t) {
      return s->val > t->val;
    }
  };

 public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<ListNode*, vector<ListNode*>, cmp> q;
    for (auto& pointer : lists)
      if (pointer != nullptr) q.push(pointer);
    auto head = new ListNode(0);
    auto res = head;
    while (!q.empty()) {
      auto qa = q.top();
      q.pop();
      res->next = qa;
      qa = qa->next;
      if (qa) q.push(qa);
      res = res->next;
    }
    res = head->next;
    delete head;
    return res;
  }
};
// @lc code=end
