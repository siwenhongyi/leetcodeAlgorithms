/*
 * @lc app=leetcode.cn id=341 lang=cpp
 *
 * [341] 扁平化嵌套列表迭代器
 */
#include "head.h"
// @lc code=start

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
/*
class NestedInteger {
 public:
  // Return true if this NestedInteger holds a single integer, rather than a
  // nested list.
  bool isInteger() const;

  // Return the single integer that this NestedInteger holds, if it holds a
  // single integer The result is undefined if this NestedInteger holds a nested
  // list
  int getInteger() const;

  // Return the nested list that this NestedInteger holds, if it holds a nested
  // list The result is undefined if this NestedInteger holds a single integer
  const vector<NestedInteger> &getList() const;
};
*/

class NestedIterator {
 private:
  using It = vector<NestedInteger>::iterator;
  stack<pair<It, It>> p;

 public:
  NestedIterator(vector<NestedInteger> &nestedList) {
    p.emplace(nestedList.begin(), nestedList.end());
  }

  int next() { return p.top().first++->getInteger(); }

  bool hasNext() {
    while (p.size()) {
      auto &qa = p.top();
      if (qa.first == qa.second) {
        p.pop();
        continue;
      }
      if (qa.first->isInteger()) return true;
      auto &ls = qa.first++->getList();
      p.emplace(ls.begin(), ls.end());
    }
    return false;
  }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
// @lc code=end
