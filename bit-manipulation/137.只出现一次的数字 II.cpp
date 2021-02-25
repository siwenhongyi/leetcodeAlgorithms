/*
* @lc app=leetcode.cn id=137 lang=cpp
*
* [137] 只出现一次的数字 II
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> x;
        for(auto &i:nums)
            x[i]++;
        for(auto &i:x)
            if(i.second==1)
                return i.first;
        return 0;
    }
};
// @lc code=end

