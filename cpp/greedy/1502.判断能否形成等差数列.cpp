/*
 * @lc app=leetcode.cn id=1502 lang=cpp
 *
 * [1502] 判断能否形成等差数列
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  bool canMakeArithmeticProgression(vector<int>& arr) {
    bool res = true;
    if (arr.size() <= 2) return res;
    sort(arr.begin(), arr.end());
    int len = arr.size(), d = arr[1] - arr[0];
    for (int i = 2; i < len; i++) {
      if (arr[i] - arr[i - 1] != d) return false;
    }
    return true;
  }
};
// @lc code=end
