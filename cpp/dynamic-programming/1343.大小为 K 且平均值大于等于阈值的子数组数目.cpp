/*
 * @lc app=leetcode.cn id=1343 lang=cpp
 *
 * [1343] 大小为 K 且平均值大于等于阈值的子数组数目
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  int numOfSubarrays(vector<int>& arr, int k, int avg) {
    int n = arr.size();
    vector<int> ad(n + 1, 0);
    for (int i = 1; i <= n; i++) ad[i] = ad[i - 1] + arr[i - 1];
    int res = 0;
    for (int i = k; i <= n; i++) {
      if ((ad[i] - ad[i - k]) / k >= avg) res++;
    }
    return res;
  }
};
// @lc code=end
