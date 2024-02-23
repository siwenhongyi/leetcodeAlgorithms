/*
 * @lc app=leetcode.cn id=1669 lang=cpp
 *
 * [1669] 合并两个链表
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  ListNode* mergeInBetween(ListNode* x, int a, int b, ListNode* y) {
    auto res = new ListNode(0);
    auto t = res;
    int cnt = 0;
    while (x) {
      if (cnt == a) {
        while (y) {
          t->next = new ListNode(y->val);
          t = t->next;
          y = y->next;
        }
        while (cnt <= b && x) {
          x = x->next;
          cnt++;
        }
      }
      t->next = new ListNode(x->val);
      x = x->next;
      t = t->next;
      cnt++;
    }
    t = res;
    res = res->next;
    delete t;
    return res;
  }
};
// @lc code=end
