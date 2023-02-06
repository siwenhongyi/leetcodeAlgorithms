/*
 * @lc app=leetcode.cn id=1798 lang=cpp
 *
 * [1798] 你能构造出连续值的最大数目
 */

#include "head.h"
using namespace std;

// @lc code=start
class Solution {
 public:
  int getMaximumConsecutive(vector<int>& coins) {
    sort(coins.begin(), coins.end());
    int n = coins.size(), res = 1, index = 0;
    while (index < n) {
      auto y = coins[index++];
      if (y <= res)
        res += y;
      else
        break;
    }
    return res;
  }
};
// @lc code=end
