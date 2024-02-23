/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  bool isPalindrome(ListNode* head) {
    string s, t;
    while (head) {
      s += '0' + head->val;
      head = head->next;
    }
    t.resize(s.size());
    reverse_copy(s.begin(), s.end(), t.begin());
    return s == t;
  }
};
// @lc code=end
