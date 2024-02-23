/*
 * @lc app=leetcode.cn id=476 lang=cpp
 *
 * [476] 数字的补数
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  int findComplement(int num) {
    long long int i = 0;
    long long int j = 1;
    long long int x = 1;
    while (x <= num) {
      x *= 2;
      i++;
    }
    x = (j << i) - 1;
    return int(num ^ x);
  }
};

// @lc code=end
