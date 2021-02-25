/*
* @lc app=leetcode.cn id=1029 lang=cpp
*
* [1029] 两地调度
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
    public:
    int twoCitySchedCost(vector<vector<int>>& costs) {

        sort(begin(costs), end(costs),[](const vector<int> &s, const vector<int> &t) 
             { return (s[0] - s[1] < t[0] -t[1]);}
            );

        int res = 0;
        int mid = costs.size() / 2;
        for (int i = 0; i < mid; i++)
            res += costs[i][0] + costs[i + mid][1];
        return res;
    }
};
// @lc code=end

