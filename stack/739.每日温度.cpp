/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */
#include "head.h"
using namespace std;
// @lc code=start
typedef pair<int, int> pp;
class Solution {
 public:
  vector<int> dailyTemperatures(vector<int>& t) {
    stack<pp> s;
    pp p;
    int n = t.size(), i = 0;
    int index;
    vector<int> res(n, 0);
    while (i < n) {
      while (!s.empty() && t[i] > (p = s.top()).first) {
        s.pop();
        res[p.second] = i - p.second;
      }
      s.push({t[i], i++});
    }
    return res;
  }
};
// @lc code=end
