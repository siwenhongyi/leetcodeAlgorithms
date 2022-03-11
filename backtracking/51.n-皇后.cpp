/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */
#include "head.h"
using namesapce std;
// @lc code=start
class Solution {
    private:
    const int N = 17;
    const int M = 8;
    vector<int> row,col,left,right;
    vector<vector<string>> res;
    int  get_status(int x,int y) {
        return ~((row[x])|(col[y])|(left[x-y+M])|(right[y-x+M]);)
    }
    void dfs(vector<string>& path,x,y,int cnt) {
        if(!cnt) return;
        auto&& status = get_status(x,y);
        for(int i = 0;i<N;i++) {
            if (!(status ^ (1 << i)))
            continue;
            path[]
        }
    }
public:
Solution():row(vector<int>(N,0)),
col(vector<int>(N,0)),
right(vector<int>(N,0)),
left(vector<int>(N,0)){}
    vector<vector<string>> solveNQueens(int n) {
        vector<string> path(n,string(n,'.'));
        dfs(path,0,0,n);
        return res;
    }
};
// @lc code=end

