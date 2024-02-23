/*
 * @lc app=leetcode.cn id=1381 lang=cpp
 *
 * [1381] 设计一个支持增量操作的栈
 */
#include "head.h"
using namespace std;
// @lc code=start
class CustomStack {
 public:
  deque<int> myst;
  int m;
  CustomStack(int maxSize) { m = maxSize; }
  void push(int x) {
    if (myst.size() == m) return;
    myst.push_back(x);
  }
  int pop() {
    if (myst.empty()) return -1;
    int x = myst.back();
    myst.pop_back();
    return x;
  }
  void increment(int k, int val) {
    int n = myst.size();
    k = min(k, n);
    for (int i = 0; i < k; i++) myst[i] += val;
    return;
  }
};
// @lc code=end
