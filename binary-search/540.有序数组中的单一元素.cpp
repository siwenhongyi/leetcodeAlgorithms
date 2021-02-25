/*
* @lc app=leetcode.cn id=540 lang=cpp
*
* [540] 有序数组中的单一元素
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int res= 0;
        for(auto &i:nums)
            res^=i;
        return res;
    }
};
// @lc code=end

