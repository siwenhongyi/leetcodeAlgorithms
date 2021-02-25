/*
* @lc app=leetcode.cn id=剑指 Offer 35 lang=cpp
*
* [剑指 Offer 35] 复杂链表的复制
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
public:
    Node*copyRandomList(Node* ph)
    {
        if (!ph)
            return NULL;
        unordered_map<Node*, Node*>  pos;
        auto head = new Node(ph->val);
        auto res = head;
        pos[ph] = head;
        if (ph->random != NULL) {
            if (ph->random == ph)
                head->random = head;
            else {
                head->random = new Node(ph->random->val);
                pos[ph->random] = head->random;
            }
        }
        ph = ph->next;
        //head = head->next;
        while (ph!=NULL) {
            auto t = pos.find(ph);
            if (t != pos.end())
                head->next = pos[ph];
            else {
                head->next = new Node(ph->val);
                pos[ph] = head->next;
            }
            if (ph->random != NULL) {
                t = pos.find(ph->random);
                if (t != pos.end())
                    head->next->random = pos[ph->random];
                else {
                    head->next->random = new Node(ph->random->val);
                    pos[ph->random] = head->next->random;
                }
            }
            ph = ph->next;
            head = head->next;
        }
        return res;
    }
};

// @lc code=end

