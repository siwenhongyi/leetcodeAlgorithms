/*
 * @lc app=leetcode.cn id=354 lang=cpp
 *
 * [354] 俄罗斯套娃信封问题
 */

#include "head.h"
using namespace std;
// @lc code=start

bool comp(const vector<int> &s, const vector<int> &t) { return s[0] < t[0]; }
class Solution {
 public:
  int maxEnvelopes(vector<vector<int>> &envelopes) {
    if (envelopes.size() <= 1) return envelopes.size();
    int n = envelopes.size();
    sort(envelopes.begin(), envelopes.end(), comp);
    vector<int> dp(n, 1);
    int res = 0;
    for (int i = 1; i < envelopes.size(); i++) {
      dp[i] = 1;
      for (int j = 0; j < i; j++) {
        if (envelopes[i][0] > envelopes[j][0] &&
            envelopes[i][1] > envelopes[j][1])
          dp[i] = max(dp[i], dp[j] + 1);
      }
      if (dp[i] > res) res = dp[i];
    }
    return res;
  }
};
// @lc code=end
