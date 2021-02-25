/*
* @lc app=leetcode.cn id=877 lang=cpp
*
* [877] 石子游戏
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
public:
    bool stoneGame(vector<int>& x) {
        return true;
        int n = x.size();
        int o,e;
        o=e=0;
        for(int i = 0;i<n;i++){
            if(i%2)
                o+=x[i];
            else
                e+=x[i];
        }
        return o>e||e>o;
    }
};
// @lc code=end

