/*
 * @lc app=leetcode.cn id=374 lang=cpp
 *
 * [374] 猜数字大小
 */
#include "head.h"
using namespace std;

// @lc code=start
/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
 public:
  int guessNumber(int n) {
    int l = 1, r = n, mid, t;
    while (l <= r) {
      mid = l + (r - l) / 2;
      t = guess(mid);
      if (t > 0) {
        l = mid + 1;
      } else if (t < 0) {
        r = mid - 1;
      } else
        return mid;
    }
    return 0;
  }
};
// @lc code=end
