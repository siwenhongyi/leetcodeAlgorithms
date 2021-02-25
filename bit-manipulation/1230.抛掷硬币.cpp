/*
* @lc app=leetcode.cn id=1230 lang=cpp
*
* [1230] 抛掷硬币
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
public:
	double probabilityOfHeads(vector<double>& p, int k) {
		double dp[1001][1001];
		int n = p.size();
		int i, j;
		dp[1][0] = 1 - p[0], dp[1][1] = p[0];
		for (i = 2; i <= n; i++) {
			dp[i][0] = dp[i - 1][0] * (1 - p[i - 1]);
			for (j = 1; j <= i; j++) {
				dp[i][j] = dp[i - 1][j - 1] * p[i - 1] + dp[i - 1][j] * (1 - p[i - 1]);
			}
		}
		return dp[n][k];
	}
};

// @lc code=end

