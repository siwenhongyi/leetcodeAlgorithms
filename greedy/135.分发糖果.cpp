/*
 * @lc app=leetcode.cn id=135 lang=cpp
 *
 * [135] 分发糖果
 */
#include "head.h"
using namesapce std;
// @lc code=start
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if(n<=1) return n;
        int res = 0;
        vector pos(n,1);
        for(int i = 1;i<n;i++) {
            if(ratings[i] > ratings[i-1])
            pos[i] = pos[i-1]+1;
        }
        int cur = 1;
        for(int i = n-1;i>=0;i--) {
            if(i+1<n&&ratings[i] > ratings[i+1]) cur++;
            else cur = 1;
            res += max(cur,pos[i]);
        }
        return res;
    }
};
// @lc code=end

