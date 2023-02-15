/*
 * @lc app=leetcode.cn id=1124 lang=cpp
 *
 * [1124] 表现良好的最长时间段 Medium (38.88%)
 */

#include "head.h"
using namespace std;

// @lc code=start
class Solution {
 public:
  int longestWPI(vector<int>& h) {
    int n = h.size();
    vector<int> s(n + 1, 0);
    stack<int> sk;
    sk.push(0);
    for (int i = 1; i <= n; i++) {
      s[i] = s[i - 1] + (h[i - 1] > 8 ? 1 : -1);
      if (s[sk.top()] > s[i]) sk.push(i);
    }
    int res = 0;
    for (int i = n - 1; i >= 0; i--) {
      while (!sk.empty() && s[i] > s[sk.top()]) {
        res = max(res, i - sk.top());
        sk.pop();
      }
    }
    return res;
  }
};
// @lc code=end
