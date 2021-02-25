/*
 * @lc app=leetcode.cn id=1071 lang=cpp
 *
 * [1071] 字符串的最大公因子
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  inline int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
  string gcdOfStrings(string s, string t) {
    if (s + t != t + s) return "";
    return s.substr(0, gcd(s.size(), t.size()));
  }
};
// @lc code=end
