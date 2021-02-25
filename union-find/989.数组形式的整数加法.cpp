/*
* @lc app=leetcode.cn id=989 lang=cpp
*
* [989] 数组形式的整数加法
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& res, int K) {
        int i,n=res.size();
        i=n-1;
        while(i>=0){
            res[i]+=K%10;
            K/=10;
            if(res[i]>9){
                res[i]-=10;
                K++;
            }
            i--;
        }
        while(K){
            res.insert(res.begin(),K%10);
            K/=10;
        }
        return res;    
    }
};
// @lc code=end

