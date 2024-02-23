/*
 * @lc app=leetcode.cn id=1639 lang=cpp
 *
 * [1639] 通过给定词典构造目标字符串的方案数
 */

#include "head.h"
using namespace std;
// @lc code=start
using PII = pair<int, int>;
using ll = long long;
int mod = 1e9 + 7;
class Solution {
 public:
  int numWays(vector<string>& words, string target) {
    int n = words.size(), m = words[0].size(), k = target.size();
    vector<vector<int>> dp(m + 1, vector<int>(k + 1, 0));
    vector<vector<int>> s(m, vector<int>(26, 0));
    for (auto& it : words)
      for (int i = 0; i < it.size(); i++) s[i][it[i] - 'a']++;
    dp[0][0] = 1;
    for (int i = 1; i <= m; i++) {
      for (int j = 0; j <= k; j++) {
        if (j > i + 1) break;
        dp[i][j] = dp[i - 1][j] % mod;
        if (j)
          dp[i][j] +=
              ((ll)s[i - 1][target[j - 1] - 'a'] * dp[i - 1][j - 1]) % mod;
        dp[i][j] %= mod;
      }
    }
    return dp.back().back();
  }
};

// @lc code=end
