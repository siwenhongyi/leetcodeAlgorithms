/*
* @lc app=leetcode.cn id=1006 lang=cpp
*
* [1006] 笨阶乘
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
public:
    int clumsy(int N) {
            if(N>4)
    {
        switch(N%4)
        {
            case 0:return N+1;break;
            case 1:return N+2;break;
            case 2:return N+2;break;
            case 3:return N-1;break;
            default:break;
        }
    }
    switch(N)
    {
        case 0:return 0;
        case 1:return 1;
        case 2:return 2;
        case 3:return 6;
        case 4:return 7;
        default:break;
    }
    return 0;
    }
};
// @lc code=end

