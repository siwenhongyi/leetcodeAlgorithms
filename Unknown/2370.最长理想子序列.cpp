/*
 * @lc app=leetcode.cn id=2370 lang=cpp
 *
 * [2370] 最长理想子序列
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
 public:
  int longestIdealString(string s, int diff) {
    int n = s.size();
    if (diff == 25) return n;
    int res = 0;
    vector<int> dp(26, 0);
    for (int i = 0; i < n; i++) {
      auto&& c = s[i] - 'a';
      auto t = dp[c];
      for (int ch = 0; ch < 26; ch++) {
        if (abs(ch - c) <= diff) {
          t = max(t, dp[ch] + 1);
        }
      }
      dp[c] = t;
      res = max(res, dp[c]);
    }
    return res;
  }
};
// @lc code=end

int main() {
  /*
   * any test cases
   */
  Solution s;
  cout << s.longestIdealString("lkpkxcigcs", 6) << endl;
  cout << s.longestIdealString("acfgbd", 2) << endl;
  cout << s.longestIdealString("abcd", 1) << endl;
  cout << s.longestIdealString("abcdgggkkk", 25) << endl;
  cout << s.longestIdealString("pvjcci", 4) << endl;
  return 0;
}
