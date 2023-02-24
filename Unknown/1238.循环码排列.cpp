/*
 * @lc app=leetcode.cn id=1238 lang=cpp
 *
 * [1238] 循环码排列 Medium (67.57%)
 */

#include "head.h"
using namespace std;

// @lc code=start
class Solution {
 public:
  vector<int> circularPermutation(int n, int start) {
    vector<int> ret(1 << n);
    for (int i = 0; i < ret.size(); i++) {
      ret[i] = (i >> 1) ^ i ^ start;
    }
    return ret;
  }
};
// @lc code=end
