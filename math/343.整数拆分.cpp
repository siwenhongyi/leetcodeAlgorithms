/*
* @lc app=leetcode.cn id=343 lang=cpp
*
* [343] 整数拆分
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
public:
    int integerBreak(int n) {
        if (n == 0)
            return 0;
        int res = 1;
        int con = n / 3;
        int c = n % 3;
        switch (c)
        {
        case 1:
            res = con > 0 ? 4 : 1, con -= 1;
            break;
        case 2:
            res = (con > 0) + 1;
            break;
        case 0:
            res = con > 1 ? 1 : (con -= 1, 2);
            break;
        }
        while (con > 0) {
            res *= 3;
            con--;
        }
        return res;
    }
};

// @lc code=end

