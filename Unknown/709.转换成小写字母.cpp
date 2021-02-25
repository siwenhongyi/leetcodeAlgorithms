/*
 * @lc app=leetcode.cn id=709 lang=cpp
 *
 * [709] 转换成小写字母
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  string toLowerCase(string str) {
    int x = 'a' - 'A';
    for (auto& it : str)
      if (it >= 'A' && it <= 'Z') it += x;
    return str;
  }
};
// @lc code=end
