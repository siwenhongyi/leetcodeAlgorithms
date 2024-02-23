/*
 * @lc app=leetcode.cn id=754 lang=cpp
 *
 * [754] 到达终点数字
 */

#include "head.h"
using namespace std;
// @lc code=start

class Solution {
 public:
  int reachNumber(int target) {
    int sum = 0;
    int i = 0;
    int a = abs(target);
    while (sum < a || (sum - a) % 2 != 0) {
      sum += i;
      i++;
    }
    return i - 1;  //因为在判断结果前都要让i+1，所以这里返回的是i-1
  }
};
// @lc code=end
