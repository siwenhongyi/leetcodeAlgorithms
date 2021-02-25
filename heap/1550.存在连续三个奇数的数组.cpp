/*
* @lc app=leetcode.cn id=1550 lang=cpp
*
* [1550] 存在连续三个奇数的数组
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int cou = 0;
        for (auto& it : arr) {
            if (it % 2)
                cou++;
            else
                cou = 0;
            if (cou == 3)
                break;
        }
        return cou == 3;
    }
};
// @lc code=end

