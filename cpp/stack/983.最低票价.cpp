/*
 * Created by 张明利 on 2024-10-9 12:16:16
 */

/*
 * @lc app=leetcode.cn id=983 lang=cpp
 *
 * [983] 最低票价
 */

#include "head.h"
using namespace std;

// @lc code=start
class Solution {
 public:
  int mincostTickets(vector<int>& days, vector<int>& costs) {
    vector<int> dp(366, 0);
    unordered_map<int, bool> mp;
    for (const auto& it : days) {
      mp[it] = true;
    }
    // m为了防止买通行证小于单次票价
    int n = days.size(), m = *min_element(costs.begin(), costs.end());
    for (int i = days[0]; i <= days[n - 1]; i++) {
      if (!mp.count(i)) {
        dp[i] = dp[i - 1];
      } else {
        dp[i] = dp[i - 1] + m;
      }
      // 可以在一开始就买通行证
      dp[i] = min(dp[i], (i - 7 >= 1 ? dp[i - 7] : 0) + costs[1]);
      dp[i] = min(dp[i], (i - 30 >= 1 ? dp[i - 30] : 0) + costs[2]);
    }
    return dp[days.back()];
  }
};
// @lc code=end
