/*
 * @lc app=leetcode.cn id=1015 lang=cpp
 *
 * [1015] 可被 K 整除的最小整数
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  int smallestRepunitDivByK(int k) {
    if (k == 1) return 1;
    string str = to_string(k);
    if (count(str.begin(), str.end(), '1') == str.size()) return str.size();
    int t = k % 10;
    if (t != 1 && t != 3 && t != 7 && t != 9) return -1;
    int res = 1;
    t = 1;
    while (t % k != 0) {
      t = (t % k) * 10 + 1;
      res++;
    }
    return res;
  }
};

// @lc code=end
