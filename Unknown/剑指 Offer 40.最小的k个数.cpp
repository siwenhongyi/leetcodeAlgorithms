/*
 * @lc app=leetcode.cn id=剑指 Offer 40 lang=cpp
 *
 * [剑指 Offer 40] 最小的k个数
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  vector<int> getLeastNumbers(vector<int>& arr, int k) {
    int n = arr.size();
    if (n <= k)
      return arr;
    else if (n < 100) {
      sort(arr.begin(), arr.end());
      arr.resize(k);
      return arr;
    } else {
      vector<int> res;
      for (int i = 0; i < k; i++) res.push_back(arr[i]);
      make_heap(res.begin(), res.end());
      int t = res.front();
      for (int i = k; i < n; i++) {
        if (arr[i] >= t)
          continue;
        else {
          pop_heap(res.begin(), res.end());
          res.pop_back();
          res.push_back(arr[i]);
          push_heap(res.begin(), res.end());
          t = res.front();
        }
      }
      // sort_heap(res.begin(), res.end());
      return res;
    }
    return {};
  }
};

// @lc code=end
