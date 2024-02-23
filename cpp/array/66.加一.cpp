/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  vector<int> plusOne(vector<int>& digits) {
    if (digits[0] == 0) return {1};
    int op = 1, temp;
    for (int i = digits.size() - 1; op && i >= 0; i--) {
      temp = digits[i] + op;
      digits[i] = temp % 10;
      op = temp / 10;
    }
    if (op) digits.insert(digits.begin(), op);
    return digits;
  }
};
// @lc code=end
