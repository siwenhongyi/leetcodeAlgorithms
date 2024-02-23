/*
 * @lc app=leetcode.cn id=769 lang=cpp
 *
 * [769] 最多能完成排序的块
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  int maxChunksToSorted(vector<int>& arr) {
    int res = 0;
    int i = 0;
    while (i < arr.size()) {
      if (arr[i] == i) {
        res++;
        i++;
      } else if (arr[i] > i) {
        bool b = false;
        int m = arr[i], j = i;
        while (j < arr.size()) {
          if (arr[j] == i) b = true;
          if (arr[j] > m) m = arr[j];
          if (b && j >= m) break;
          j++;
        }
        res++;
        i = j + 1;
      }
    }
    return res;
  }
};

// @lc code=end
