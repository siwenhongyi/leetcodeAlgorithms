/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  ListNode* getIntersectionNode(ListNode* ha, ListNode* hb) {
    if (!ha || !hb) return nullptr;
    auto a = ha, b = hb;
    while (a || b) {
      if (a == b) return a;
      if (a)
        a = a->next;
      else
        a = hb;
      if (b)
        b = b->next;
      else
        b = ha;
    }
    return nullptr;
  }
};

// @lc code=end
