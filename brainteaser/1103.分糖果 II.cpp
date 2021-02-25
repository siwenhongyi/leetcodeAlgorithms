/*
* @lc app=leetcode.cn id=1103 lang=cpp
*
* [1103] 分糖果 II
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> distributeCandies(int cs, int n) {
        vector<int> res(n,0);
        int c = 1;
        while(cs){
            for(int i = 0;i<n;i++){
                if(c<=cs){
                    res[i] += c;
                    cs -= c++;
                }
                else{
                    res[i] += cs;
                    cs=0;
                }
            }
        }
        return res;
    }
};
// @lc code=end

