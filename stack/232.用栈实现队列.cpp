/*
* @lc app=leetcode.cn id=232 lang=cpp
*
* [232] 用栈实现队列
*/

#include"head.h"
using namespace std;
// @lc code=start
class MyQueue {
	stack<int> res;
public:
	/** Initialize your data structure here. */
	MyQueue() {

	}

	/** Push element x to the back of queue. */
	void push(int x) {
		res.push(x);
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop() {
		stack<int> t;
		while (res.size() != 1) {
			t.push(res.top());
			res.pop();
		}
        int x = res.top();
		res.pop();
		while (!t.empty()) {
			res.push(t.top());
			t.pop();
		}
		return x;
	}

	/** Get the front element. */
	int peek() {
		stack<int> t = res;
		while (t.size() != 1)
			t.pop();
		return t.top();
	}

	/** Returns whether the queue is empty. */
	bool empty() {
		return res.empty();
	}
};

// @lc code=end

