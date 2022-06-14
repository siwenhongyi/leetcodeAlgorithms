/*
 * @lc app=leetcode.cn id=218 lang=cpp
 *
 * [218] 天际线问题
 */
#include "head.h"
using namespace std;
// @lc code=start
// 线段树
class SegmentTree {
 public:
  SegmentTree(vector<int>& nums) {
    int n = nums.size();
    tree.resize(4 * n);
    build(nums, 0, n - 1, 0);
  }
  void update(int i, int val) { update(i, val, 0, n - 1, 0); }
  int query(int i, int j) { return query(i, j, 0, n - 1, 0); }

 private:
  vector<int> tree;
  int n;
  void build(vector<int>& nums, int l, int r, int idx) {
    if (l == r) {
      tree[idx] = nums[l];
      return;
    }
    int mid = (l + r) / 2;
    build(nums, l, mid, idx * 2 + 1);
    build(nums, mid + 1, r, idx * 2 + 2);
    tree[idx] = tree[idx * 2 + 1] + tree[idx * 2 + 2];
  }
  void update(int i, int val, int l, int r, int idx) {
    if (l == r) {
      tree[idx] = val;
      return;
    }
    int mid = (l + r) / 2;
    if (i <= mid)
      update(i, val, l, mid, idx * 2 + 1);
    else
      update(i, val, mid + 1, r, idx * 2 + 2);
    tree[idx] = tree[idx * 2 + 1] + tree[idx * 2 + 2];
  }
  int query(int i, int j, int l, int r, int idx) {
    if (i > r || j < l) return 0;
    if (i <= l && j >= r) return tree[idx];
    int mid = (l + r) / 2;
    return query(i, j, l, mid, idx * 2 + 1) +
           query(i, j, mid + 1, r, idx * 2 + 2);
  }
};

class Solution {
 public:
  vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {}
};
// @lc code=end
