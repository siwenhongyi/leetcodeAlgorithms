/*
* @lc app=leetcode.cn id=203 lang=cpp
*
* [203] 移除链表元素
*/

#include"head.h"
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
    ListNode* removeElements(ListNode* head, int val) {
        if(!head)
            return head;
        ListNode *p,*t;
        while(head&&head->val==val){
            p = head;
            head = head->next;
            delete p;
        }
        t = head;
        while(head&&head->next){
            if(head->next->val == val){
                p = head -> next;
                head->next = p->next;
                delete p;
            }
            else
                head = head->next;
        }
        return t;
    }
};
// @lc code=end

