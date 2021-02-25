/*
 * @lc app=leetcode.cn id=1374 lang=cpp
 *
 * [1374] 生成每种字符都是奇数个的字符串
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  string generateTheString(int n) {
    if (n % 2) return string(n, 'a');
    string res(n - 1, 'a');
    res.resize(n, 'b');
    return res;
  }
};

// @lc code=end
