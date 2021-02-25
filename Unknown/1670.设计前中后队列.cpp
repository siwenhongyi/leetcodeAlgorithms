/*
* @lc app=leetcode.cn id=1670 lang=cpp
*
* [1670] 设计前中后队列
*/

#include"head.h"
using namespace std;
// @lc code=start
class FrontMiddleBackQueue {
private:
    vector<int> pos;
public:
    FrontMiddleBackQueue() {

    }
    void pushFront(int val) {
        if (pos.empty())pos.push_back(val);
        else
            pos.insert(pos.begin(),val);
    }

    void pushMiddle(int val) {
        if (pos.empty())pos.push_back(val);
        else
            pos.insert(pos.begin() + (pos.size() / 2), val);
    }

    void pushBack(int val) {
        pos.push_back(val);
    }

    int popFront() {
        if (pos.empty())return -1;
        auto res = pos.front();
        pos.erase(pos.begin());
        return res;
    }

    int popMiddle() {
        if (pos.empty())return -1;
        auto res = *(pos.begin() + ((pos.size() - 1) / 2));
        pos.erase(pos.begin() + ((pos.size()-1) / 2));
        return res;

    }

    int popBack() {
        if (pos.empty())return -1;
        auto res = pos.back();
        pos.pop_back();
        return res;

    }
};
// @lc code=end

