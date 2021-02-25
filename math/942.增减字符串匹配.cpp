/*
* @lc app=leetcode.cn id=942 lang=cpp
*
* [942] 增减字符串匹配
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> diStringMatch(string S) {
        if(S.empty())
            return {};      
        vector<int> res;
        int i = 0,j = S.size();
        for(auto c:S)
            if(c=='I')
                res.push_back(i++);
            else
                res.push_back(j--);
        if(S.back()=='I')
            res.push_back(i);
        else
             res.push_back(j);
        return res;
    }
};
// @lc code=end

