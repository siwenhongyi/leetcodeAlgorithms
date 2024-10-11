/*
 * Created by 张明利 on 2024年10月11日星期五 10:39:15
 */

/*
 * @lc app=leetcode.cn id=134 lang=cpp
 *
 * [134] 加油站
 */

#include "head.h"
using namespace std;

// @lc code=start
class Solution {
  using pii = pair<int, int>;

 public:
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int total_cost = 0;
    pii res = pii(0, 0);
    size_t n = gas.size();
    for (size_t i = 1; i < n; i++) {
      total_cost += gas[i - 1] - cost[i - 1];
      if (total_cost < res.second) {
        res = {i, total_cost};
      }
    }
    total_cost += gas.back() - cost.back();
    return total_cost < 0 ? -1 : res.first;
  }
};
// @lc code=end
