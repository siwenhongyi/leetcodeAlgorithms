/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * [91] 解码方法
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  int numDecodings(string s) {
    if (s.empty() || s.front() == '0') return 0;
    int n = s.size();
    vector<int> dp(s.size() + 1, 1);
    for (int i = 1; i < n; i++) {
      if (s[i] == '0')
        if (s[i - 1] == '1' || s[i - 1] == '2')
          dp[i + 1] = dp[i - 1];
        else
          return 0;
      else if ((s[i - 1] == '1' ||
                (s[i - 1] == '2') && s[i] >= '1' && s[i] <= '6'))
        dp[i + 1] = dp[i] + dp[i - 1];
      else
        dp[i + 1] = dp[i];
    }
    return dp.back();
  }
};

// @lc code=end
