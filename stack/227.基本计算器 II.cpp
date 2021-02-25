/*
 * @lc app=leetcode.cn id=227 lang=cpp
 *
 * [227] 基本计算器 II
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  int calculate(string s) {
    string ops = "+-*/";
    int pre, cur, next;
    pre = cur = next = 0;
    char op = '+', c;
    int i = 0, n = s.size();
    while (i < n) {
      if (s[i] == ' ') {
        i++;
        continue;
      }
      if (ops.find(s[i]) != string::npos) {
        if (op == '+') {
          pre += cur;
          cur = next;
        } else if (op == '-') {
          pre += cur;
          cur = -next;
        } else if (op == '*')
          cur *= next;
        else
          cur /= next;
        op = s[i];
        next = 0;
        i++;
      } else {
        next = next * 10 + (s[i++] - '0');
      }
    }
    if (op == '*')
      cur *= next;
    else if (op == '/')
      cur /= next;
    else if (op == '+')
      cur += next;
    else
      cur -= next;
    return pre + cur;
  }
};

// @lc code=end
