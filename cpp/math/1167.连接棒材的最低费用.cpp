/*
 * @lc app=leetcode.cn id=1167 lang=cpp
 *
 * [1167] 连接棒材的最低费用
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  int connectSticks(vector<int>& sticks) {
    priority_queue<int, vector<int>, greater<int>> q(sticks.begin(),
                                                     sticks.end());
    int res = 0;
    while (q.size() > 1) {
      auto a = q.top();
      q.pop();
      auto b = q.top();
      q.pop();
      q.push(a + b);
      res += a + b;
    }
    return res;
  }
};

// @lc code=end
