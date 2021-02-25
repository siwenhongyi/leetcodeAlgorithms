/*
* @lc app=leetcode.cn id=1323 lang=cpp
*
* [1323] 6 和 9 组成的最大数字
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
public:
    int maximum69Number(int num) {
        string x = to_string(num);
        for (int i = 0; i < x.size(); i++)
            if (x[i] == '6') {
                x[i] = '9';
                return atoi(x.c_str());
            }
        return num;
    }
};
// @lc code=end

