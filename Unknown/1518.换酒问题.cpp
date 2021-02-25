/*
* @lc app=leetcode.cn id=1518 lang=cpp
*
* [1518] 换酒问题
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int res = numBottles;
        int t;
        while (numBottles >= numExchange) {
            t = numBottles / numExchange;
            numBottles = (numBottles%numExchange) + t;
            res += t;
        }
        return res;
    }
};

// @lc code=end

