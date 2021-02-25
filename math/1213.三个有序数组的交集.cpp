/*
 * @lc app=leetcode.cn id=1213 lang=cpp
 *
 * [1213] 三个有序数组的交集
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2,
                                 vector<int>& arr3) {
    if (arr1.empty() || arr2.empty() || arr3.empty()) return {};
    int i, j, k, t;
    int m = min(arr1.size(), min(arr2.size(), arr3.size()));
    vector<int> res;
    i = j = k = 0;
    while (true) {
      if (arr1[i] == arr2[j] && arr2[j] == arr3[k]) {
        res.push_back(arr2[j]);
        i++;
        j++;
        k++;
      } else {
        t = min(arr1[i], min(arr2[j], arr3[k]));
        if (arr1[i] == t) i++;
        if (arr2[j] == t) j++;
        if (arr3[k] == t) k++;
      }
      if (i == m || j == m || k == m) break;
    }
    return res;
  }
};
// @lc code=end
