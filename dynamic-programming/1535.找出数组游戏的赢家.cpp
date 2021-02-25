/*
 * @lc app=leetcode.cn id=1535 lang=cpp
 *
 * [1535] 找出数组游戏的赢家
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  int getWinner(vector<int>& arr, int k) {
    int i = 0, t = 0;  // t记录连胜次数
    while (t < k && i < arr.size() - 1) {
      if (arr[i] > arr[i + 1]) {
        arr[i + 1] = arr[i];
        ++t;
      } else
        t = 1;
      ++i;
    }
    return arr[i];
  }
};

// @lc code=end
