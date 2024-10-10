/*
 * Created by 张明利 on 10-10-2024, 4:39:10 PM
 */

/*
 * @lc app=leetcode.cn id=2187 lang=cpp
 *
 * [2187] 完成旅途的最少时间
 */

#include "head.h"
using namespace std;

// @lc code=start
class Solution {
  using ll = long long;
  bool check(const vector<int>& t, const ll& ma, const ll& need) {
    ll ans = 0;
    for (auto& it : t) {
      ans += ma / ll(it);
    }
    return ans >= need;
  }

 public:
  long long minimumTime(vector<int>& time, int totalTrips) {
    ll l = 0, r = 1e14, need = ll(totalTrips);
    while (l <= r) {
      ll m = (l + r) >> 1;
      if (check(time, m, need)) {
        r = m - 1;
      } else {
        l = m + 1;
      }
    }
    return l;
  }
};
// @lc code=end
