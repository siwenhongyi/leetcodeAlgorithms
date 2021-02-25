/*
 * @lc app=leetcode.cn id=552 lang=cpp
 *
 * [552] 学生出勤记录 II
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 private:
  int mod = 1e9 + 7;

 public:
  int checkRecord(int n) {
    vector<int> pos(3, 1), t(3);
    pos[2] = 0;
    for (int i = 2; i <= n; i++) {
      t[0] = (pos[0] + pos[1] + pos[2]) % mod;
      t[1] = pos[0];
      t[2] = pos[1];
      pos.swap(t);
    }
    long long int res = (pos[0] + pos[1] + pos[2]) % mod;
    res = res * (n + 1) - res;
    return res % mod;
  }
};
// @lc code=end
