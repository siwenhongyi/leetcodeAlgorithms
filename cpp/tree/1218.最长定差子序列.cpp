/*
 * @lc app=leetcode.cn id=1218 lang=cpp
 *
 * [1218] 最长定差子序列
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  int longestSubsequence(vector<int>& arr, int difference) {
    if (arr.size() <= 1) return arr.size();
    unordered_map<int, int> pos;
    int n = arr.size();
    pos[arr[0]] = 1;
    int t, res = 1;
    for (int i = 1; i < n; i++) {
      t = pos[arr[i] - difference];
      if (!t)
        pos[arr[i]] = 1;
      else
        pos[arr[i]] = ++t;
      res = max(res, t);
    }
    return res;
  }
};

// @lc code=end
