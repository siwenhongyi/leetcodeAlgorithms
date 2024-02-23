/*
 * @lc app=leetcode.cn id=2335 lang=cpp
 *
 * [2335] 装满杯子需要的最短总时长 Easy (57.13%)
 */

#include "head.h"
using namespace std;

// @lc code=start
class Solution {
 public:
  int fillCups(vector<int>& nums) {
    int res = 0;
    int big, bigi, mid, midi;
    auto &a = nums[0], &b = nums[1], &c = nums[2];
    while (a + b + c != 0) {
      // cout<<a<<' '<<b<<' '<<c<<endl;
      big = a, bigi = 0, mid = b, midi = 1;
      for (int i = 1; i < 3; i++) {
        if (nums[i] >= big) {
          mid = big, midi = bigi;
          big = nums[i], bigi = i;
        }
      }
      // 只有一个情况
      if (nums[midi] == 0) {
        nums[bigi]--;
      } else {
        nums[bigi]--, nums[midi]--;
      }
      res++;
    }
    return res;
  }
};
// @lc code=end
