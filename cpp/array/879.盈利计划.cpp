/*
 * @lc app=leetcode.cn id=879 lang=cpp
 *
 * [879] 盈利计划
 */

// @lc code=start
class Solution {
 private:
  const static int mod = 1e9 + 7;

 public:
  int profitableSchemes(int n, int m, vector<int>& group, vector<int>& profit) {
    int ss = group.size(), r, f;
    vector<vector<vector<int>>> dp(
        ss + 1, vector<vector<int>>(n + 1, vector<int>(m + 1, 0)));
    dp[0][0][0] = 1;
    for (int i = 1; i <= ss; i++) {
      r = group[i - 1], f = profit[i - 1];
      for (int j = 0; j <= n; j++) {
        for (int k = 0; k <= m; k++) {
          dp[i][j][k] =
              j < r ? dp[i - 1][j][k]
                    : (dp[i - 1][j][k] + dp[i - 1][j - r][max(0, k - f)]) % mod;
        }
      }
    }
    int res = 0;
    for (auto& it : dp.back()) res = (res + it.back()) % mod;
    return res;
  }
};
// @lc code=end
