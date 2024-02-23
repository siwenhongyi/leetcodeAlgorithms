/*
 * @lc app=leetcode.cn id=2315 lang=cpp
 *
 * [2315] 统计星号
 */

#include "head.h"
using namespace std;

// @lc code=start
class Solution {
 public:
  int countAsterisks(string s) {
    int res = 0, op = 1;
    for (auto& c : s) {
      if (c == '|')
        op *= -1;
      else if (c == '*' && op == 1)
        res++;
    }
    return res;
  }
};
// @lc code=end
