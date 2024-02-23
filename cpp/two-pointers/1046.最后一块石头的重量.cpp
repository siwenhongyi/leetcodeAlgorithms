/*
 * @lc app=leetcode.cn id=1046 lang=cpp
 *
 * [1046] 最后一块石头的重量
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  int lastStoneWeight(vector<int>& stones) {
    int zeros = stones.size();
    while (zeros > 1) {
      sort(stones.rbegin(), stones.rend());
      if (stones[1] == 0) break;
      stones[0] -= stones[1];
      stones[1] -= stones[1];
    }
    return stones[0];
  }
};
// @lc code=end
