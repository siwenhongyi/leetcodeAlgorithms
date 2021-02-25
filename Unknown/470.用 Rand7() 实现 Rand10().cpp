/*
* @lc app=leetcode.cn id=470 lang=cpp
*
* [470] 用 Rand7() 实现 Rand10()
*/

#include"head.h"
using namespace std;
// @lc code=start
// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        while(true)
        {
            int a=(rand7()-1)*7+rand7();//1-49
            if(a<=40) 
                return a%10+1;//n%10 得到 0-9  
        }
        return 0;
    }
};
// @lc code=end

