/*
 * @lc app=leetcode.cn id=1630 lang=cpp
 *
 * [1630] 等差子数组
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l,
                                        vector<int>& r) {
    if (l.empty()) return {};
    vector<bool> res;
    for (int i = 0; i < l.size(); i++) {
      if (l[i] >= r[i]) {
        res.push_back(l[i] == r[i]);
        continue;
      }
      vector<int> t;
      for (int j = l[i]; j <= r[i]; j++) t.push_back(nums[j]);
      sort(t.begin(), t.end());
      int k = t[1] - t[0];
      bool x = true;
      for (int j = 2; j < t.size() && x; j++)
        if (t[j] - t[j - 1] == k)
          continue;
        else
          x = false;
      res.push_back(x);
    }
    return res;
  }
};

// @lc code=end
