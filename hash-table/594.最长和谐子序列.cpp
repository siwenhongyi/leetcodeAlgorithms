/*
 * @lc app=leetcode.cn id=594 lang=cpp
 *
 * [594] 最长和谐子序列
 */

#include "head.h"
using namespace std;
// @lc code=start
struct stnode {
  int num;
  int mi, mx, length;
};
class Solution {
 public:
  int findLHS(vector<int>& nums) {
    unordered_map<int, int> cnt;
    for (auto& it : nums) cnt[it]++;
    int res = 0;
    for (auto& it : cnt) {
      auto&& [num, sz] = it;
      if (cnt.count(num + 1)) res = max(res, sz + cnt[num + 1]);
    }
    return res;
  }
};
// @lc code=end
