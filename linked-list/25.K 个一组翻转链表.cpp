/*
* @lc app=leetcode.cn id=25 lang=cpp
*
* [25] K 个一组翻转链表
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
	ListNode* reverseKGroup(ListNode* head, int k) {
		if (!head || k == 1)
			return head;
		ListNode *re, *w, *p, *q;
		ListNode h(-1);
		h.next = head;
		q = re = &h;
		p = head;
		while (true) {
			for (int i = 0; i < k; i++) {
				if (q->next)
					q = q->next;
				else
					return h.next;
			}
			w = p;
			while (p != q) {
				re->next = p->next;
				p->next = q->next;
				q->next = p;

				p = re->next;

			}
			re = w;
			q = re;
			p= re->next;
		}
		return h.next;
	}

};
// @lc code=end

