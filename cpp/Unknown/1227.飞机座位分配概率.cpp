/*
 * Created by 张明利 on 10-10-2024, 4:15:30 PM
 */

/*
 * @lc app=leetcode.cn id=1227 lang=cpp
 *
 * [1227] 飞机座位分配概率
 */

#include "head.h"
using namespace std;

// @lc code=start
class Solution {
 public:
  double nthPersonGetsNthSeat(int n) { return n == 1 ? 1.0 : 0.5; }
};
// @lc code=end
