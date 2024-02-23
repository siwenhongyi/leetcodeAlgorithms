/*
 * @lc app=leetcode.cn id=1446 lang=cpp
 *
 * [1446] 连续字符
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  int maxPower(string s) {
    int res = 0, n = s.size(), index = 0;
    int temp;
    while (index < n) {
      char pre = s[index];
      temp = 0;
      while (index < n && s[index] == pre) index++, temp++;
      res = max(res, temp);
    }
    return res;
  }
};
// @lc code=end
