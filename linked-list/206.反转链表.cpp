/*
* @lc app=leetcode.cn id=206 lang=cpp
*
* [206] 反转链表
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next)
            return head;
        auto p = head;
        while (p->next)
            p = p->next;
        while (head != p) {
            auto t = p->next;
            p->next = head;
            auto r = head->next;
            head->next = t;
            head = r;
        }
        return p;
    }
};

// @lc code=end

