/*
* @lc app=leetcode.cn id=1198 lang=cpp
*
* [1198] 找出所有行中最小公共元素
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        if(mat.size()==1)
            return mat[0][0];
        //for(auto &i:mat)
         //   sort(i.begin(),i.end());
        //sort(mat.begin(),mat.end(),[](const vector<int>&s,const vector<int>&t){return s[0]<t[0];});
        int n = mat.size(),j;
        for(auto &i :mat[0]){
            for(j = 1;j<n;j++)
                if(find(mat[j].begin(),mat[j].end(),i)==mat[j].end())
                    break;
            if(j==n)
                return i;          
        }
        return -1;
    }
};
// @lc code=end

