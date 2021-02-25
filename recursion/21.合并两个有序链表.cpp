/*
* @lc app=leetcode.cn id=21 lang=cpp
*
* [21] 合并两个有序链表
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* f1, ListNode* f2) {
		if (f1 == NULL && f2 == NULL)
			return NULL;

		if (f1 == NULL || f2 == NULL)
			return f1 == NULL ? f2 : f1;
		ListNode *head = f1, *p = f1, *t;
		while (f1 && f2)
		{
			if (f2->val <= f1->val) {
				if (f1 == head) {
					head = f2;
					f2 = head->next;
					head->next = f1;
					p = head;
					continue;
				}
				else {
					t = f2;
					f2 = f2->next;

					p->next = t;
					t->next = f1;

					p = t;
					continue;
				}
			}
			p = f1;
			f1 = f1->next;
		}
		if (f2)
			p->next = f2;
		return head;
	}

};

// @lc code=end

