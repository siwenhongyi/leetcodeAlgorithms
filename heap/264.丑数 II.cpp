/*
 * @lc app=leetcode.cn id=264 lang=cpp
 *
 * [264] 丑数 II
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  int nthUglyNumber(int n) {
    if (n == 1) return 1;
    vector<int> res = {1};
    int i, j, k;
    i = j = k = 0;
    while (res.size() < n) {
      int x = min(res[i] * 2, min(res[j] * 3, res[k] * 5));
      res.push_back(x);
      while (res[i] * 2 <= x) i++;
      while (res[j] * 3 <= x) j++;
      while (res[k] * 5 <= x) k++;
    }
    return res.back();
  }
};
// @lc code=end
