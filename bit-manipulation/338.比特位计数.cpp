/*
* @lc app=leetcode.cn id=338 lang=cpp
*
* [338] 比特位计数
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> countBits(int n) {
       if(n==0)
           return {0};
        if(n==1)
            return{0,1};
        if(n==2)
            return {0,1,1};
        vector<int> res = {0,1,1};
        int index = 1,m = 3;
        while(m<=n){
            if((m&m-1)==0){
                res.push_back(1);
                index = 1;
            }
            else
                res.push_back(res[index++]+1);
            m++;
        }
       // res.resize(n);
        return res;
    }
};
// @lc code=end

