/*
 * @lc app=leetcode.cn id=1792 lang=cpp
 *
 * [1792] 最大平均通过率 Medium (51.46%)
 */

#include "head.h"
using namespace std;

// @lc code=start
class Solution {
  using vi = vector<int>;
  struct cmp {
    int x, y;
    bool operator<(const cmp& s) const {
      auto&& a = double(x + 1) / (y + 1) - double(x) / y;
      auto&& b = double(s.x + 1) / (s.y + 1) - double(s.x) / s.y;
      return a < b;
    }
  };

 public:
  double maxAverageRatio(vector<vector<int>>& classes, int et) {
    priority_queue<cmp> q;
    int n = classes.size();

    for (int i = 0; i < n; i++) q.push({classes[i][0], classes[i][1]});
    while (et--) {
      auto [a, b] = q.top();
      q.pop();
      q.push({a + 1, b + 1});
    }
    double res = 0;
    while (q.size()) {
      auto&& [a, b] = q.top();
      // cout << '[' << a << ',' << b << "]\n";
      res += double(a) / b;
      q.pop();
    }
    return res / n;
  }
};
// @lc code=end
