/*
 * @lc app=leetcode.cn id=剑指 Offer 59 - II lang=cpp
 *
 * [剑指 Offer 59 - II] 队列的最大值
 */
#include "head.h"
using namespace std;
// @lc code=start
class MaxQueue {
  queue<int> q;
  deque<int> m;

 public:
  MaxQueue() {}
  int max_value() {
    if (m.empty()) return -1;
    return m.front();
  }
  void push_back(int value) {
    while (!m.empty() && m.back() < value) m.pop_back();
    m.push_back(value);
    q.push(value);
  }
  int pop_front() {
    if (q.empty()) return -1;
    auto qa = q.front();
    q.pop();
    if (qa == m.front()) m.pop_front();
    return qa;
  }
};
// @lc code=end
