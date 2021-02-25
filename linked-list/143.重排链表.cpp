/*
* @lc app=leetcode.cn id=143 lang=cpp
*
* [143] 重排链表
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
	void reorderList(ListNode* head) {
        if(!head)
            return;
		vector<ListNode*> pos;
		while (head)
		{
			pos.push_back(head);
			head = head->next;
		}
		int mid = pos.size() / 2;
		reverse(pos.begin() + mid, pos.end());
		for (int i = 0; i < mid; i++) {
			ListNode* t = pos[i]->next;
			pos[i]->next = pos[i + mid];
			pos[i + mid]->next = t;
		}
		pos[pos.size() - 1]->next = NULL;
	}
};


// @lc code=end

