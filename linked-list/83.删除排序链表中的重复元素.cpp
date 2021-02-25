/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  ListNode* deleteDuplicates(ListNode* head) {
    if (!head || !head->next) return head;
    unordered_map<int, int> pos;
    ListNode *p = head, *pre = head;
    while (p) {
      if (pos[p->val]++) {
        pre->next = p->next;
        delete p;
        p = pre->next;
      } else {
        pre = p;
        p = p->next;
      }
    }
    return head;
  }
};

// @lc code=end
