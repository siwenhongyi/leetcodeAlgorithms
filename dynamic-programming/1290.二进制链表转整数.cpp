/*
 * @lc app=leetcode.cn id=1290 lang=cpp
 *
 * [1290] 二进制链表转整数
 */

#include "head.h"
using namespace std;
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
 public:
  int getDecimalValue(ListNode* head) {
    int res = 0;
    while (head) {
      // res <<= 1;
      // res |= head->val;
      res = (res << 1) | (head->val);
      head = head->next;
    }
    return res;
  }
};
// @lc code=end
