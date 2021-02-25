/*
* @lc app=leetcode.cn id=1672 lang=cpp
*
* [1672] 最富有客户的资产总量
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
public:
    int maximumWealth(vector<vector<int>>& mat) {
        int res = 0;
        for(auto&it:mat){
            int t = 0;
            for(auto&iter:it) t += iter;
            res = max(res,t);
        }
        return res;
    }
};
// @lc code=end

