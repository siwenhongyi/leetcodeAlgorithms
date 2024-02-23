/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  int majorityElement(vector<int>& p) {
    int res, count = 0;
    for (auto& it : p)
      if (count == 0) {
        res = it;
        count++;
      } else
        count -= it == res ? -1 : 1;
    return res;
  }
};
// @lc code=end
