/*
* @lc app=leetcode.cn id=141 lang=cpp
*
* [141] 环形链表
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
    bool hasCycle(ListNode *head) {
        if(!head)
          return false;
        auto second = head;
        auto first = head->next;
        if(first)
          first = first->next;
        else
          return false;
        while(first&&second&&first!=second){
            first = first->next;
            if(first) {
                first = first->next;
            } else
            return false;
            second = second->next;
        }
        return first == second;
    }
};
// @lc code=end

