/*
 * Created by 张明利 on 2024年10月12日星期六 12:20:39
 */

/*
 * @lc app=leetcode.cn id=2181 lang=cpp
 *
 * [2181] 合并零之间的节点
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
  ListNode* mergeNodes(ListNode* head) {
    auto curr = head->next;
    // delete head;
    auto res = new ListNode(-1);
    auto res_l = res;
    // ListNode* temp = nullptr;
    while (curr) {
      int v = 0;
      while (curr && curr->val != 0) {
        v += curr->val;
        // temp = curr->next;
        // delete curr;
        curr = curr->next;
      }
      res_l->next = new ListNode(v);
      res_l = res_l->next;
      // temp = curr->next;
      // delete curr;
      curr = curr->next;
    }
    // res_l = res;
    // res = res->next;
    // delete res_l;
    return res->next;
  }
};
// @lc code=end

/*
 * base .vscode/extensions/leetcode.vscode-leetcode-0.18.4/
 * base dir node_modules/vsc-leetcode-cli/
 * template file templates/codeonly.tpl
 * path args in file lib/core.js:135
 */
