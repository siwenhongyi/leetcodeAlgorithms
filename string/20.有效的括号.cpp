/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */
#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 private:
  stack<char> st;

 public:
  bool isValid(string s) {
    // do it two times
    for (auto& c : s) {
      switch (c) {
        case ')':
        case ']':
        case '}': {
          if (st.empty()) return false;
          auto&& qa = c - st.top();
          if (qa < 0 || qa > 2) return false;
          st.pop();
          break;
        }
        default:
          st.push(c);
          break;
      }
    }
    return st.empty();
  }
};
// @lc code=end
