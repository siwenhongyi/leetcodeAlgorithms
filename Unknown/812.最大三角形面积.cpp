/*
* @lc app=leetcode.cn id=812 lang=cpp
*
* [812] 最大三角形面积
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& v) {
        double x,y,z;
        int n = v.size();
        double p,t,res = 0;
        for(int i = 0;i<n-2;i++){
            for(int j = i+1;j<n-1;j++){
                for(int k = j+1;k<n;k++){
                    x = sqrt(pow(v[i][0]-v[j][0],2)+pow(v[i][1]-v[j][1],2));
                    y = sqrt(pow(v[i][0]-v[k][0],2)+pow(v[i][1]-v[k][1],2));
                    z = sqrt(pow(v[j][0]-v[k][0],2)+pow(v[j][1]-v[k][1],2));
                    p = (x+y+z)/2;
                    t = sqrt(p*(p-x)*(p-y)*(p-z));
                    if(t>res)
                        res = t;
                }
            }
        }
        return res;
    }
};
// @lc code=end

