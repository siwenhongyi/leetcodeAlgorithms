/*
 * @lc app=leetcode.cn id=1472 lang=cpp
 *
 * [1472] 设计浏览器历史记录
 */
#include "head.h"
using namespace std;
// @lc code=start
class BrowserHistory {
 public:
  stack<string> head, b;
  BrowserHistory(string homepage) { head.push(homepage); }
  void visit(string url) {
    head.push(url);
    stack<string> tmp;
    b.swap(tmp);
  }
  string back(int steps) {
    while (steps-- && head.size() > 1) {
      auto tmp = head.top();
      head.pop();
      b.push(tmp);
    }
    return head.top();
  }
  string forward(int steps) {
    while (steps-- && b.size() > 0) {
      auto tmp = b.top();
      b.pop();
      head.push(tmp);
    }
    return head.top();
  }
};
// @lc code=end
