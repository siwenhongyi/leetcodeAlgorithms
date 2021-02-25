/*
 * @lc app=leetcode.cn id=1561 lang=cpp
 *
 * [1561] 你可以获得的最大硬币数目
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  int maxCoins(vector<int>& piles) {
    sort(piles.begin(), piles.end());
    int l = 0, r = piles.size() - 1;
    int res = 0;
    while (r - l != 2) {
      res += piles[r - 1];
      l++, r -= 2;
    }
    res += piles[r - 1];
    return res;
  }
};
// @lc code=end
