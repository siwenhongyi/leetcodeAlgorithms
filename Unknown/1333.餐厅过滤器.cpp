/*
* @lc app=leetcode.cn id=1333 lang=cpp
*
* [1333] 餐厅过滤器
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& r, int v, int mp, int md) {
        vector<int> res;
        vector<vector<int> > ans;
        int n = r.size();
        for(auto &it:r){
            if((v&&!it[2])||it[3]>mp||it[4]>md)
                continue;
            ans.push_back({it[0],it[1]});
        }
        sort(ans.begin(),ans.end(),[](const vector<int> &s,const vector<int> &t){return s[1]==t[1]?s[0]>t[0]:s[1]>t[1];});
        for(auto &it:ans)
            res.push_back(it[0]);
        return res;
    }
};
// @lc code=end

