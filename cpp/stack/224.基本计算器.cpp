/*
 * @lc app=leetcode.cn id=224 lang=cpp
 *
 * [224] 基本计算器
 */
#include "head.h"
// @lc code=start
class Solution {
 public:
  int calculate(string s) {
    long long int res = 0;
    stack<int> op;
    op.push(1);
    int index = 0, n = s.size(), pre = 1;
    char c;
    while (index < n) {
      c = s[index];
      if (c == ' ') {
        index++;
        continue;
      } else if (c >= '0' && c <= '9') {
        int j = index;
        long long int t = 0;
        while (j < n) {
          if (s[j] >= '0' && s[j] <= '9') {
            t = t * 10 + s[j++] - '0';
          } else if (s[j] == ' ') {
            j++;
            continue;
          } else
            break;
        }
        res += (op.top() * pre) * t;
        index = j - 1;
      } else {
        if (c == '(') {
          op.push(pre * op.top());
        } else if (c == ')') {
          op.pop();
        }
        pre = c == '-' ? -1 : 1;
      }
      index++;
    }
    return res;
  }
};
// @lc code=end
