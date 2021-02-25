/*
* @lc app=leetcode.cn id=1344 lang=cpp
*
* [1344] 时钟指针的夹角
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
public:
    double angleClock(int h, int m) {
        double x = (h % 12) * 30 + (m / 60.0) * 30;
        double y = (m / 60.0) * 360;
        x = abs(x - y);
        return min(x, 360 - x);
    }
};
// @lc code=end

