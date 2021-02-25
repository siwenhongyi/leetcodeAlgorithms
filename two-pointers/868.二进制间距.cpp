/*
 * @lc app=leetcode.cn id=868 lang=cpp
 *
 * [868] 二进制间距
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  int binaryGap(int N) {
    bitset<32> pos(N);
    if (pos.count() <= 1) return 0;
    int i, j, res;
    i = res = 0;
    while (i < 32 && !pos[i]) i++;
    while (i < 32) {
      j = i + 1;
      while (j < 32 && !pos[j]) j++;
      if (j < 32) res = max(res, j - i);
      i = j;
    }
    return res;
  }
};

// @lc code=end
