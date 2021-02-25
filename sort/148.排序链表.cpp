/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  // static bool comp(const ListNode* s,const ListNode* t){
  //     return s->val<t->val;
  // }
  ListNode* sortList(ListNode* head) {
    if (!head) return head;
    vector<ListNode*> pos;
    while (head) {
      pos.push_back(head);
      head = head->next;
    }
    int n = pos.size();
    sort(pos.begin(), pos.end(),
         [](const ListNode* s, const ListNode* t) { return s->val < t->val; });
    // sort(pos.begin(),pos.end(),comp);
    for (int i = 0; i < n; i++) {
      if (i != n - 1)
        pos[i]->next = pos[i + 1];
      else
        pos[i]->next = NULL;
    }
    return pos.front();
  }
};
// @lc code=end
