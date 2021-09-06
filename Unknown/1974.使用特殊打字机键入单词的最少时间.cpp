/*
 * @lc app=leetcode.cn id=1974 lang=cpp
 *
 * [1974] 使用特殊打字机键入单词的最少时间
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  int minTimeToType(string word) {
    int res, cur, temp;
    res = cur = temp = 0;
    for (auto& it : word) {
      temp = it - 'a';

      if (temp == cur) {
        res++;
      } else {
        res += min((26 - cur + temp) % 26, (cur - temp + 26) % 26);
        res++;
        cur = temp;
      }
    }
    return res;
  }
};
// @lc code=end
