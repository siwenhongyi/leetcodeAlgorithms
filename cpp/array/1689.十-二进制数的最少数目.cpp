/*
 * @lc app=leetcode.cn id=1689 lang=cpp
 *
 * [1689] 十-二进制数的最少数目
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  int minPartitions(string n) {
    map<char, int> pos;
    int m = 0;
    for (auto& it : n) {
      if (it != '0') pos[it]++;
      m = max(m, pos[it]);
    }
    int res = 0, x = 0;
    for (auto& it : pos) {
      // if (it.second == 0)continue;
      int t = it.first - '0' - x;
      res += t;
      x += t;
    }
    return res;
  }
};
// @lc code=end
