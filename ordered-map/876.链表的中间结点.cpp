/*
* @lc app=leetcode.cn id=876 lang=cpp
*
* [876] 链表的中间结点
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
    ListNode* middleNode(ListNode* head) {
        if(head==NULL||head->next==NULL)
            return head;
        vector<ListNode*> v;
        while(head){
            v.push_back(head);
            head = head->next;
        }
            return v[v.size()/2];

    }
};
// @lc code=end

