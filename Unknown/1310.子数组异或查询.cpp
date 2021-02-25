/*
* @lc app=leetcode.cn id=1310 lang=cpp
*
* [1310] 子数组异或查询
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& q) {
        if(q.empty())
            return {};
        vector<int> ans(q.size());
        int res=0,l,r = -1;
        int p=0,qq;
        for(auto &it:q)
            it.push_back(p++);
        
        sort(q.begin(),q.end());
        for(auto &it:q){
            if(it[0]>r){
                res = 0;
                l = it[0],r=it[1];
                for(int i = l;i<=r;i++){
                    res ^= arr[i];
                }
            }
            else{
                p = min(r,it[1]),qq = max(r,it[1]);
                for(int i = p+1;i<=qq;i++)
                    res^=arr[i];
                for(int i = l;i<it[0];i++)
                    res^=arr[i];
                l = it[0],r = it[1];
            }
            ans[it[2]] = res;
        }
        return ans;
    }
};
// @lc code=end

