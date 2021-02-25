/*
* @lc app=leetcode.cn id=225 lang=cpp
*
* [225] 用队列实现栈
*/

#include"head.h"
using namespace std;
// @lc code=start
class MyStack {
public:
    queue<int> my, t;
    /** Initialize your data structure here. */
    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {
        while (!my.empty()) {
            auto qa = my.front();
            my.pop();
            t.push(qa);
        }
        my.push(x);
        while (!t.empty()) {
            auto qa = t.front();
            t.pop();
            my.push(qa);
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        auto qa = my.front();
        my.pop();
        return qa;
    }

    /** Get the top element. */
    int top() {
        return my.front();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return my.empty();
    }
};

// @lc code=end

