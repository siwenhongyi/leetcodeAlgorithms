/*
* @lc app=leetcode.cn id=807 lang=cpp
*
* [807] 保持城市天际线
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int res = 0;
        unordered_map<int,int> x,y;
        int i = 0,n = grid.size(),m=grid[0].size();
        for(auto &it:grid)
            x[i++] = *max_element(it.begin(),it.end());
        int j,t,ans;
        i = j =0;
       while(j<m){
            t = grid[0][j];
           for(i = 1;i<n;i++)
               if(grid[i][j]>t)
                   t = grid[i][j];
           y[j]=t;
           i=0;
           j++;
        }
        i = 0;
        while(i<n){
            j = 0;
            ans = x[i];
            while(j<m){
                t = min(ans,y[j]);
                if(grid[i][j]<t)
                    res += t - grid[i][j];
                j++;
            }
            i++;
        }
        return res;
    }
};
// @lc code=end

