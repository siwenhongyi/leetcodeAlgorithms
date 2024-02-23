/*
 * @lc app=leetcode.cn id=1196 lang=cpp
 *
 * [1196] 最多可以买到的苹果数量
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  int maxNumberOfApples(vector<int>& arr) {
    if (arr.empty()) return 0;
    sort(arr.begin(), arr.end());
    int i = 0, sum = 0, n = arr.size();
    int res = 0;
    while (i < n && sum <= 5000) {
      sum += arr[i++];
      if (sum <= 5000) res++;
    }
    return res;
  }
};

// @lc code=end
