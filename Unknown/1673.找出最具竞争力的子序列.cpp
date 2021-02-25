/*
 * @lc app=leetcode.cn id=1673 lang=cpp
 *
 * [1673] 找出最具竞争力的子序列
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  vector<int> mostCompetitive(vector<int>& nums, int k) {
    stack<int> q;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      int t = nums[i];
      if (q.empty()) {
        q.push(t);
        continue;
      }
      if (t < q.top()) {
        int need = n - i;
        while (q.size() && q.size() + need > k && t < q.top()) q.pop();
        q.push(t);
      } else if (q.size() < k)
        q.push(t);
    }
    vector<int> res(k);
    for (int i = k - 1; i >= 0; i--) {
      res[i] = q.top();
      q.pop();
    }
    return res;
  }
};
// @lc code=end
