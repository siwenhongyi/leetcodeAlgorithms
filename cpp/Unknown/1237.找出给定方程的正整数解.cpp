/*
 * @lc app=leetcode.cn id=1237 lang=cpp
 *
 * [1237] 找出给定方程的正整数解 Medium (71.87%)
 */

#include "head.h"
using namespace std;

// This is the custom function interface.
// You should not implement it, or speculate about its implementation
class CustomFunction {
 public:
  // Returns f(x, y) for any given positive integers x and y.
  // Note that f(x, y) is increasing with respect to both x and y.
  // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
  int f(int x, int y) { return x + y; }
};

// @lc code=start
/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     int f(int x, int y);
 * };
 */

class Solution {
  vector<vector<int>> findSolution_binarySearch(CustomFunction& c, int z) {
    vector<vector<int>> res;
    for (int x = 1, y; x <= 1000; x++) {
      int l = 1, r = 1000;
      while (l <= r) {
        y = (l + r) >> 1;
        auto&& fres = c.f(x, y);
        if (fres == z) {
          res.push_back({x, y});
          break;
        }
        if (fres > z)
          r = y - 1;
        else
          l = y + 1;
      }
    }
    return res;
  }
  vector<vector<int>> findSolution_twoPoint(CustomFunction& c, int z) {
    vector<vector<int>> res;
    int x = 1, y = 1000;
    while (x <= 1000 && y > 0) {
      while (y > 0 && c.f(x, y) > z) y--;
      if (y > 0 && c.f(x, y) == z) {
        res.push_back({x, y});
      }
      x++;
    }
    return res;
  }

 public:
  vector<vector<int>> findSolution(CustomFunction& c, int z) {
    return findSolution_twoPoint(c, z);
  }
};
// @lc code=end
