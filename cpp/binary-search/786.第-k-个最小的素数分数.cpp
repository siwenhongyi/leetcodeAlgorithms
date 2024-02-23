/*
 * @lc app=leetcode.cn id=786 lang=cpp
 *
 * [786] 第 K 个最小的素数分数
 */

#include "head.h"
using namespace std;
// @lc code=start
using iid = tuple<int, int, double>;
struct cmp {
  bool operator()(const iid& s, const iid& t) {
    auto&& [a, b, c] = s;
    auto&& [x, y, z] = t;
    return c < z;
  }
};

class Solution {
 public:
  vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
    priority_queue<iid, vector<iid>, cmp> res;
    int n = arr.size();
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        double temp = arr[i] * 1.0 / arr[j];
        if (res.size() < k)
          res.emplace(arr[i], arr[j], temp);
        else {
          auto&& [a, b, c] = res.top();
          if (temp < c) {
            res.pop();
            res.emplace(arr[i], arr[j], temp);
          }
        }
      }
    }
    auto&& [a, b, c] = res.top();
    return {a, b};
  }
};
// @lc code=end
