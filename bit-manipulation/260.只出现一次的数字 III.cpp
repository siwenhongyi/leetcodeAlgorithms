/*
* @lc app=leetcode.cn id=260 lang=cpp
*
* [260] 只出现一次的数字 III
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int,int> x;
        for(auto &i:nums)
            x[i]++;
        vector<int> res;
        for(auto &i:x){
            if(i.second==1)
                res.push_back(i.first);
            if(res.size()==2)
                break;
        }
        return res;
    }
};
// @lc code=end

