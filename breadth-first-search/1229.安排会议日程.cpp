/*
 * @lc app=leetcode.cn id=1229 lang=cpp
 *
 * [1229] 安排会议日程
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  vector<int> minAvailableDuration(vector<vector<int>>& s,
                                   vector<vector<int>>& t, int duration) {
    int i, j, m = s.size(), n = t.size();
    i = j = 0;
    int p, pp;
    sort(s.begin(), s.end(), [](const vector<int>& q, const vector<int>& qq) {
      if (q[0] != qq[0]) return q[0] < qq[0];
      return q[1] < qq[1];
    });
    sort(t.begin(), t.end(), [](const vector<int>& q, const vector<int>& qq) {
      if (q[0] != qq[0]) return q[0] < qq[0];
      return q[1] < qq[1];
    });
    while (i < m && j < n) {
      if (s[i][0] > t[j][1] || t[j][0] > s[i][1]) {
        s[i][1] < t[j][1] ? i++ : j++;
        continue;
      }
      p = max(s[i][0], t[j][0]), pp = min(s[i][1], t[j][1]);
      if (pp - p >= duration) return {p, p + duration};
      s[i][1] < t[j][1] ? i++ : j++;
    }
    return {};
  }
};
// @lc code=end
