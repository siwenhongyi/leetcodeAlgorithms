/*
 * @lc app=leetcode.cn id=1503 lang=cpp
 *
 * [1503] 所有蚂蚁掉下来前的最后一刻
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  int getLastMoment(int n, vector<int>& left, vector<int>& right) {
    if (left.empty() && right.empty()) return 0;
    int res = -1;
    if (!left.empty()) res = max(*max_element(left.begin(), left.end()), res);
    if (!right.empty())
      res = max(n - *min_element(right.begin(), right.end()), res);
    return res;
  }
};
// @lc code=end
