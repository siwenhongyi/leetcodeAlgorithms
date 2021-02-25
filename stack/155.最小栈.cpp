/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */
#include "head.h"
using namespace std;
// @lc code=start
class MinStack {
  stack<int> res, t;

 public:
  /** initialize your data structure here. */
  MinStack() {}
  void push(int x) {
    res.push(x);
    if (t.size() == 0 || x <= t.top()) t.push(x);
  }
  void pop() {
    if (res.top() == t.top()) t.pop();
    res.pop();
  }
  int top() { return res.top(); }
  int getMin() { return t.top(); }
};
// @lc code=end
