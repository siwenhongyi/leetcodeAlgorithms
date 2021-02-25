/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  bool isValid(string s) {
    set<char> left_side{'(', '[', '{'};
    map<char, char> side{{')', '('}, {']', '['}, {'}', '{'}};
    stack<char> left;
    for (auto& it : s) {
      if (left_side.count(it))
        left.push(it);
      else {
        auto t = side[it];
        if (left.empty() || left.top() != t)
          return false;
        else
          left.pop();
      }
    }
    return left.empty();
  }
};

// @lc code=end
