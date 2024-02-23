/*
 * @lc app=leetcode.cn id=2544 lang=cpp
 *
 * [2544] 交替数字和
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  int alternateDigitSum(int n) {
    int res = 0, op = 1;
    string s(to_string(n));
    for (auto& it : s) {
      auto&& num = it - '0';
      res += num * op;
      op *= -1;
    }
    return res;
  }
};
// @lc code=end
