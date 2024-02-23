/*
 * @lc app=leetcode.cn id=LCP 01 lang=cpp
 *
 * [LCP 01] 猜数字
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  int game(vector<int>& guess, vector<int>& answer) {
    int res = 0, i;
    for (i = 0; i < guess.size(); i++)
      if (guess[i] == answer[i]) res++;
    return res;
  }
};
// @lc code=end
