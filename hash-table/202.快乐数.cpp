/*
* @lc app=leetcode.cn id=202 lang=cpp
*
* [202] 快乐数
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
public:
    int fun(int x){
        int sum = 0,t;
        while(x){
            t = x%10;
            sum+=pow(t,2);
            x/=10;
        }
        return sum;
    }
    bool isHappy(int n) {
        int l = n,r = fun(n);
        while(l!=r){
            l = fun(l);
            r = fun(fun(r));
        }
        return l==1;
    }
};
// @lc code=end

