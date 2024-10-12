/*
 * Created by 张明利 on 2024年10月12日星期六 11:21:31
 */

/*
 * @lc app=leetcode.cn id=2708 lang=cpp
 *
 * [2708] 一个小组的最大实力值
 */

#include "head.h"
using namespace std;

// @lc code=start
class Solution {
  using ll = long long;

 public:
  long long maxStrength(vector<int>& nums) {
    int n = nums.size();
    vector<vector<ll>> dp(n, vector<ll>(2));
    for (size_t i = 0; i < n; i++) {
      auto c = ll(nums[i]);
      dp[i][0] = dp[i][1] = c;
      for (size_t j = 0; j < i; j++) {
        dp[i][0] = max(dp[i][0], dp[j][0]);
        dp[i][1] = min(dp[i][1], dp[j][0]);
        dp[i][0] = max(dp[i][0], c * dp[j][0]);
        dp[i][0] = max(dp[i][0], c * dp[j][1]);
        dp[i][1] = min(dp[i][1], c * dp[j][0]);
        dp[i][1] = min(dp[i][1], c * dp[j][1]);
      }
    }
    // for (auto& it : dp) {
    //   for (auto& j : it) {
    //     cout << j << ' ';
    //   }
    //   cout << endl;
    // }
    return max(dp[n - 1][0], dp[n - 1][1]);
  }
};
// @lc code=end

/*
 * base .vscode/extensions/leetcode.vscode-leetcode-0.18.4/
 * base dir node_modules/vsc-leetcode-cli/
 * template file templates/codeonly.tpl
 * path args in file lib/core.js:135
 */
