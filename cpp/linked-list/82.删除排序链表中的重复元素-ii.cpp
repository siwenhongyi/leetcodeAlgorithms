/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
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
  ListNode* deleteDuplicates(ListNode* head) {
    if (head == nullptr) return head;
    stack<ListNode*> st;
    st.push(head);
    int pre = head->val, cnt = 1;
    ListNode *res = head, *temp;
    head = head->next;
    while (head) {
      temp = head->next;
      if (head->val == pre) {
        cnt++;
        temp = head->next;
        st.top()->next = temp;
        delete head;
        head = temp;
      } else {
        if (cnt > 1) {
          temp = st.top();
          st.pop();
          if (st.empty())
            res = head;
          else
            st.top()->next = head;
          delete temp;
        }
        st.push(head);
        pre = head->val, cnt = 1;
        head = head->next;
      }
    }
    if (cnt > 1) {
      temp = st.top();
      st.pop();
      if (st.empty())
        res = nullptr;
      else
        st.top()->next = nullptr;
      delete temp;
    }
    return res;
  }
};
// @lc code=end
