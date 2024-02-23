/*
 * @lc app=leetcode.cn id=2517 lang=cpp
 *
 * [2517] 礼盒的最大甜蜜度
 */

#include "head.h"
using namespace std;

// @lc code=start
class Solution {
 public:
  int maximumTastiness(vector<int>& price, int k) {
    int n = price.size();
    sort(price.begin(), price.end());
    // 检查数组中是否存在k个数，符合差最小值为k
    auto&& check = [&](int LIM) {
      // 记录一共取出几个数
      int cnt = 1;
      // j 指向上一次取得数，i 指向当前考虑的数
      for (int i = 1, j = 0; i < n; i++) {
        // price[i] 是大于等于 price[j] + LIM 的最小值，取出
        if (price[i] - price[j] >= LIM) cnt++, j = i;
      }
      return cnt >= k;
    };

    int l = 0, r = price.back(), res = 0;
    while (l < r) {
      // 防止head + 1 = tail 时，head = mid 导致死循环。
      auto mid = (l + r + 1) >> 1;
      if (check(mid)) {
        res = mid;
        l = mid;
      } else
        r = mid - 1;
    }
    return res;
  }
};
// @lc code=end
