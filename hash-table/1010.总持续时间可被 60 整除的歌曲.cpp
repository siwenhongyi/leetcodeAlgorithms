/*
* @lc app=leetcode.cn id=1010 lang=cpp
*
* [1010] 总持续时间可被 60 整除的歌曲
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        map<int,int> pos;
        int res = 0;
        for(auto &it:time)
            pos[it%60]++;
        for(auto &it:pos){
            if(it.first > 30)
                break;
            else if(it.first==30||it.first==0)
                res+= it.second*(it.second-1)/2;
            else
                res+= it.second * pos[60-it.first];
        }
        return res;
    }
};
// @lc code=end

