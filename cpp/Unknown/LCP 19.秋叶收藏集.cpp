/*
 * @lc app=leetcode.cn id=LCP 19 lang=cpp
 *
 * [LCP 19] 秋叶收藏集
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  int minimumOperations(string s) {
    int n = s.size();
    int a, b, c;
    a = s[0] == 'y';
    b = c = INT_MAX - 10;
    for (int i = 1; i < n; i++) {
      int r = (s[i] == 'r');
      int y = (s[i] == 'y');
      c = min(b, c) + y;
      b = min(a, b) + r;
      a = a + y;
    }
    return c;
  }
};

// @lc code=end
