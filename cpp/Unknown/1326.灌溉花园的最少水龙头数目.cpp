/*
 * @lc app=leetcode.cn id=1326 lang=cpp
 *
 * [1326] 灌溉花园的最少水龙头数目 Hard (48.31%)
 */

#include "head.h"
using namespace std;

// @lc code=start
class Solution {
  using pii = pair<int, int>;

 public:
  int minTaps(int n, vector<int>& ranges) {
    int index = 0, ln, rn;
    vector<pii> sk(n + 10);
    for (int i = 0; i <= n; i++) {
      if (ranges[i] == 0) continue;
      /*
      auto &&ln = max(0, i - ranges[i]), &&rn = min(n, i + ranges[i]);
      使用右值引用 lc报错 本地正常 原因未知
      */
      auto ln = max(0, i - ranges[i]), rn = min(n, i + ranges[i]);
      if (index == 0) {
        sk[index++] = {ln, rn};
        continue;
      }
      while (index) {
        auto&& [l, r] = sk[index - 1];
        // 完全覆盖
        if (ln <= l) index--;
        // 被完全覆盖 相离
        else if ((ln >= l && rn <= r) || (ln > r))
          break;
        // 相交
        else if (ln >= l && rn > r) {
          // 不止一个 检查能否删除最后一个
          if (index > 1) {
            auto&& [lp, rp] = sk[index - 2];
            if (ln <= rp) index--;
          }
          sk[index++] = {ln, rn};
          break;
        }
      }
      if (index == 0) sk[index++] = {ln, rn};
    }
    return (index && sk[index - 1].second == n) ? index : -1;
  }
};
// @lc code=end
