/*
 * @lc app=leetcode.cn id=1021 lang=cpp
 *
 * [1021] 删除最外层的括号
 */

#include "head.h"
using namespace std;
// @lc code=start

class Solution {
 public:
  string removeOuterParentheses(string S) {
    string res;
    if (!S.size()) return res;
    int left = 0, right = 0;
    int i = 0, j = 0;
    while (i < S.size()) {
      string t(1, S[i]);
      left = 1;
      i++;
      while (left) {
        if (S[i] == '(')
          left++;
        else
          left--;
        t.push_back(S[i++]);
      }
      if (t.size() > 2) res.insert(res.end(), t.begin() + 1, t.end() - 1);
    }
    return res;
  }
};

// @lc code=end
