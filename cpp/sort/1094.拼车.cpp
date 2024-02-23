/*
 * @lc app=leetcode.cn id=1094 lang=cpp
 *
 * [1094] 拼车
 */
#include "head.h"
using namespace std;
// @lc code=start
#include <iostream>
#include <vector>
using namespace std;
class Solution {
 public:
  bool carPooling(vector<vector<int>>& trips, int capacity) {
    if (trips.size() == 0) return true;
    bool res = true;
    int x[3] = {capacity, 0, 0};
    for (int i = 0; i <= 1000; i++) {
      for (int j = 0; j < trips.size(); j++) {
        if (trips[j][2] == i) {
          capacity += trips[j][0];
          continue;
        }
        if (trips[j][1] == i) {
          capacity -= trips[j][0];
        }
      }
      if (capacity < 0) return false;
    }
    return res;
  }
};
// @lc code=end
