/*
 * @lc app=leetcode.cn id=1574 lang=cpp
 *
 * [1574] 删除最短的子数组使剩余数组有序
 */

#include "head.h"
using namespace std;

// @lc code=start
class Solution {
 public:
  int findLengthOfShortestSubarray(vector<int>& arr) {
    int n = arr.size();
    if (n <= 1) return 0;
    int l = 1, r = n - 2;
    while (l < n && arr[l] >= arr[l - 1]) l++;
    // 递增
    if (l == n) return 0;
    // 删除右边所有
    int res = n - l--;
    while (r > l && arr[r + 1] >= arr[r]) r--;
    // 递减
    if (++r == n - 1 && l == 0) return n - 1 - int(arr.back() >= arr.front());
    // 比较 删除左边所有 那个删除的少
    res = min(res, r);
    // cout << l << ' ' << r << endl;
    int ll = 0, rl = r;
    while (ll <= l && rl < n) {
      if (arr[ll] <= arr[rl]) {
        res = min(res, rl - ll - 1);
        ll++;
      } else
        rl++;
    }
    return res;
  }
};
// @lc code=end
