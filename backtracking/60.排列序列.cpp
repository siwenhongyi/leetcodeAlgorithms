/*
 * @lc app=leetcode.cn id=60 lang=cpp
 *
 * [60] 排列序列
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
  static constexpr array factorial{1, 1, 2, 6, 24, 120, 720, 5040, 40320};

 public:
  string getPermutation(int n, int k) {
    vector nums(n, 0);
    iota(begin(nums), end(nums), 1);
    string res;
    --k;
    for (int i = n - 1; i >= 0; i--) {
      auto it = begin(nums) + k / factorial[i];
      res += ('0' + *it);
      nums.erase(it);
      k %= factorial[i];
    }
    return res;
  }
};
// @lc code=end
