/*
* @lc app=leetcode.cn id=64 lang=cpp
*
* [64] 最小路径和
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
public:
    int minPathSum(vector<vector<int>>& g) {
        vector<vector<int>> dp(g);
        int n = g.size(), m = g[0].size();
        for (int i = n-1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (i == n - 1 && j != m - 1)
                    dp[i][j] = g[i][j] + dp[i][j + 1];
                else if (j == m - 1 && i != n - 1)
                    dp[i][j] = g[i][j] + dp[i + 1][j];
                else if (j != m - 1 && i != n - 1)
                    dp[i][j] = g[i][j] + min(dp[i + 1][j], dp[i][j + 1]);
                else
                    dp[i][j] = g[i][j];
            }
        }
        return dp[0][0];
    }
};
// @lc code=end

