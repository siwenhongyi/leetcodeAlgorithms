/*
* @lc app=leetcode.cn id=657 lang=cpp
*
* [657] 机器人能否返回原点
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
public:
    bool judgeCircle(string moves) {
        int  a, b;
        a = b = 0;
        for (auto& it : moves) {
            if (it == 'R' || it == 'L')
                a += it == 'R' ? 1 : -1;
            else
                b += it == 'U' ? 1 : -1;
        }
        return a==0&&b==0;
    }
};
// @lc code=end

