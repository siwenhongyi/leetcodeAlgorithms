/*
 * @lc app=leetcode.cn id=面试题 16.26 lang=cpp
 *
 * [面试题 16.26] 计算器
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  int calculate(string s) {
    if (s.empty()) return 0;
    deque<int> num;
    deque<char> op;
    int n = s.size();
    long long sum = 0;
    for (int i = 0; i < n; i++) {
      auto& it = s[i];
      if (it == ' ')
        continue;
      else if (it == '+' || it == '-') {
        num.push_back(sum);
        sum = 0;
        op.push_back(it);
      } else if (it == '*' || it == '/') {
        int two = 0;
        int j = i + 1;
        for (; j < n; j++) {
          if (s[j] == ' ')
            continue;
          else if (s[j] >= '0' && s[j] <= '9')
            two = two * 10 + s[j] - '0';
          else
            break;
        }
        sum = it == '*' ? sum * two : sum / two;
        i = j - 1;
      } else {
        sum = sum * 10 + it - '0';
      }
    }
    num.push_back(sum);
    while (!op.empty()) {
      int a = num.front();
      num.pop_front();
      int b = num.front();
      num.pop_front();
      char x = op.front();
      op.pop_front();
      num.push_front(x == '+' ? a + b : a - b);
    }
    return num.front();
  }
};

// @lc code=end
