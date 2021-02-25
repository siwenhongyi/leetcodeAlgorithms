/*
* @lc app=leetcode.cn id=59 lang=cpp
*
* [59] 螺旋矩阵 II
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if(n==0)
            return {};
        if(n==1)
            return {{1}};
        vector<vector<int> > res(n,vector<int>(n,0));
        int i,j;
        int x = 1,t = n*n+1;
        i = j =0;
        while(x!=t){
            while(j<n&&res[i][j]==0)
                res[i][j++]=x++;
            j--,i++;
            while(i<n&&res[i][j]==0)
                res[i++][j]=x++;
            i--,j--;
            while(j>=0&&res[i][j]==0)
                res[i][j--]=x++;
            j++,i--;
            while(i>=0&&res[i][j]==0)
                res[i--][j] = x++;
            i++,j++;            
        }
        return res;
    }
};
// @lc code=end

