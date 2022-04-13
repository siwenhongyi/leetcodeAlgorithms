/*
 * @lc app=leetcode.cn id=89 lang=cpp
 *
 * [89] 格雷编码
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  vector<int> grayCode(int n) {
    vector<int> ret(1 << n);
    for (int i = 0; i < ret.size(); i++) {
      ret[i] = (i >> 1) ^ i;
    }
    return ret;
  }
};
// @lc code=end
