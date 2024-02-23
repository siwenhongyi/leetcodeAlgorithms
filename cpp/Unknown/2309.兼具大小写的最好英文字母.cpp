/*
 * @lc app=leetcode.cn id=2309 lang=cpp
 *
 * [2309] 兼具大小写的最好英文字母
 */

#include "head.h"
using namespace std;

// @lc code=start
class Solution {
 public:
  string greatestLetter(string s) {
    int lower, upper;
    lower = upper = 0;
    for (auto& it : s) {
      if (it >= 'a' && it <= 'z')
        lower |= (1 << (it - 'a'));
      else
        upper |= (1 << (it - 'A'));
    }
    for (int i = 25; i >= 0; i--) {
      if (lower & (1 << i) && upper & (1 << i)) return string(1, 'A' + i);
    }
    return "";
  }
};
// @lc code=end
