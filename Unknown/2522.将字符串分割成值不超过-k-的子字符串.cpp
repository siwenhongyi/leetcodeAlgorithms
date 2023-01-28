/*
 * @lc app=leetcode.cn id=2522 lang=cpp
 *
 * [2522] 将字符串分割成值不超过 K 的子字符串
 */

#include "head.h"
using namespace std;

// @lc code=start
class Solution {
  using ll = long long;

 public:
  int minimumPartition(string s, int k) {
    int n = s.size();
    // if (k > n) return 1;
    ll num = 0;
    int res = 0;
    for (auto& it : s) {
      auto&& now = it - '0';
      if (now > k) return -1;
      num = num * 10 + now;
      if (num > k) {
        res++;
        num = now;
      }
    }
    return res + 1;
  }
};
// @lc code=end
