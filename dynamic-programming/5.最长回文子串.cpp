/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */
#include "head.h"
// @lc code=start
class Solution {
 public:
  string longestPalindrome(string s) {
    if (s.empty()) return s;
    string str = "#";
    for (auto& it : s) {
      str.push_back(it);
      str.push_back('#');
    }
    int n = str.size();
    vector<int> dp(n, 1);
    int Center, Right;  // 目前最长回文串的中心 和 半径
    int mc, mr, t;
    mc = mr = Center = Right = 0;
    for (int i = 0; i < n; i++) {
      // 2 * Center - i 是i关于Center的对称点Center - (i - Center)
      // Right - i 是防止 超出已经探索的最有边界
      t = Right > i ? min(dp[2 * Center - i], Right - i) : 1;
      while (i + t < n && i - t >= 0 && str[i + t] == str[i - t]) t++;
      if (i + t > Right) {
        Right = i + t, Center = i;
      }
      if (t > mr) {
        mc = i, mr = t;
      }
      dp[i] = t;
    }
    string res;
    for (int i = mc - mr + 1; i < mc + mr; i++) {
      if (str[i] != '#') res.push_back(str[i]);
    }
    return res;
  }
};
// @lc code=end
