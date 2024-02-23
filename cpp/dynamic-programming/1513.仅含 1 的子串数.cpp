/*
 * @lc app=leetcode.cn id=1513 lang=cpp
 *
 * [1513] 仅含 1 的子串数
 */

#include "head.h"
using namespace std;
// @lc code=start
using ll = long long;
static constexpr int P = int(1E9) + 7;
class Solution {
 public:
  int numSub(string s) {
    map<ll, ll> cnt;
    ll pre = 0;
    int ret = 0;
    for (char ch : s)
      if (ch == '0') {
        if (pre) cnt[pre]++;
        pre = 0;
      } else
        pre++;
    if (pre) cnt[pre]++;
    ll res = 0;
    for (auto& it : cnt) {
      res = ((it.first * (it.first + 1)) / 2) * it.second;
      res %= P;
      ret += res;
    }
    return ret;
  }
};
// @lc code=end
