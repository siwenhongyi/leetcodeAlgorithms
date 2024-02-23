/*
 * @lc app=leetcode.cn id=463 lang=cpp
 *
 * [463] 岛屿的周长
 */
#include "head.h"
using namespace std;

// @lc code=start
class Solution {
private:
static constexpr int fx[] ={-1,1,0,0};
static constexpr int fy[] = {0,0,-1,1};
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size(),res=0;

        for(int i = 0;i<n;i++)
            for(int j = 0;j<m;j++)
                if(grid[i][j]){
                    int new_x,new_y;
                    for(int k = 0;k<4;k++) {
                        new_x = i + fx[k],new_y = j + fy[k];
                        if(new_x < 0 || new_x >= n || new_y<0 || new_y >=m)
                            res += 1;
                        else if(!grid[new_x][new_y])
                            res += 1;
                    }
                }
        return res;
    }
};
// @lc code=end

