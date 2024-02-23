/*
 * @lc app=leetcode.cn id=2347 lang=cpp
 *
 * [2347] 最好的扑克手牌 Easy (54.29%)
 */

#include "head.h"
using namespace std;

// @lc code=start
class Solution {
 public:
  string bestHand(vector<int>& ranks, vector<char>& suits) {
    /*
    "Flush"：同花，五张相同花色的扑克牌。
    "Three of a Kind"：三条，有 3 张大小相同的扑克牌。
    "Pair"：对子，两张大小一样的扑克牌。
    "High Card"：高牌，五张大小互不相同的扑克牌。
    */
    int i = 1;
    while (i < 5 && suits[i] == suits[0]) i++;
    if (i == 5) return "Flush";
    unordered_map<int, int> t;
    for (auto& it : ranks) {
      if (++t[it] == 3) return "Three of a Kind";
      if (t[it] == 2) i = 0;
    }
    if (!i) return "Pair";
    return "High Card";
  }
};
// @lc code=end
