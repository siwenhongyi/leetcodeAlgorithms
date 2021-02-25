/*
* @lc app=leetcode.cn id=1688 lang=cpp
*
* [1688] 比赛中的配对次数
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
public:
    int numberOfMatches(int n) {
        int res = 0;
        while (n != 1) {
            res += n / 2;
                n = n / 2 + (n % 2);
        }
        return  res;
    }
};
// @lc code=end

