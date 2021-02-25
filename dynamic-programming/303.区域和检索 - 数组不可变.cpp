/*
 * @lc app=leetcode.cn id=303 lang=cpp
 *
 * [303] 区域和检索 - 数组不可变
 */

#include "head.h"
using namespace std;
// @lc code=start
class NumArray {
  vector<int> p, q;

 public:
  NumArray(vector<int>& nums) {
    p.swap(nums);
    int n = p.size();
    q.resize(n + 1, 0);
    for (int i = 0; i < n; i++) {
      q[i + 1] = q[i] + p[i];
    }
  }

  int sumRange(int i, int j) { return q[j + 1] - q[i]; }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
// @lc code=end
