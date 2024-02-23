/*
 * @lc app=leetcode.cn id=899 lang=cpp
 *
 * [899] 有序队列
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  string orderlyQueue(string s, int k) {
    if (k == 1) {
      string res = s;
      int mid = s.size();
      s += s;
      for (int i = 0; i < mid; i++) {
        string t(s.begin() + i, s.begin() + i + mid);
        if (t < res) res = t;
      }
      return res;
    } else
      sort(s.begin(), s.end());
    return s;
  }
};
// @lc code=end
