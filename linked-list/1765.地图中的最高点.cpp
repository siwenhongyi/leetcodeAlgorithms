/*
* @lc app=leetcode.cn id=1765 lang=cpp
*
* [1765] 地图中的最高点
*/

#include"head.h"
using namespace std;
// @lc code=start
using PII = pair<int, int>;
class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        queue<PII> q;
        unordered_set<int> pos;
        int n = isWater.size(), m = isWater[0].size();
        int new_x, new_y;
        vector<vector<int>> res(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (isWater[i][j]) {
                    q.push({ i,j });
                    pos.insert(i * m + j);
                }
        int fx[] = { -1,0,1,0 }, fy[] = { 0,1,0,-1 };
        while (q.size()) {
            auto&& [x,y] = q.front();
            //auto qa = q.front();
            //x = qa.first,y = qa.second;
            //q.pop();
            for (int i = 0; i < 4; i++) {
                new_x = x + fx[i]; new_y = y + fy[i];
                if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < m && !pos.count(new_x * m + new_y)) {
                    res[new_x][new_y] = res[x][y] + 1;
                    pos.insert(new_x * m + new_y);
                    q.push({ new_x,new_y });
                }
            }
            q.pop();
        }
        return res;
    }
};
// @lc code=end

