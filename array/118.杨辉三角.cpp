/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 */
#include "head.h"
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for(int i = 1;i<=numRows;i++)
            res.push_back(vector<int>(i,1));
        if(numRows <= 2) return res;
        for(int i = 2;i<numRows;i++){
            for(int j = 1;j<i;j++) {
                res[i][j] = res[i-1][j] + res[i-1][j-1];
            }
        }
        return res;
    }
};
// @lc code=end

