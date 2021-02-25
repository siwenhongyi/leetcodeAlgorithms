/*
* @lc app=leetcode.cn id=486 lang=cpp
*
* [486] 预测赢家
*/

#include"head.h"
using namespace std;
// @lc code=start

#include<list>
#include<queue>
#include<unordered_map>
#include<string>
#include<unordered_set>
#include<iomanip>
#include<math.h>
#include<set>
#include<map>
#include<vector>
#include<algorithm>
#include<string>
#include <iostream>
using namespace std;

class Solution {
public:
	bool PredictTheWinner(vector<int>& nums) {
		int n = nums.size();
        if(n%2==0)
            return true;
		vector<vector<int> > dp(n, vector<int>(n, 0));
		//初始化
		for (int i = 0; i < n; i++) {
			dp[i][i] = nums[i];
		}
		for (int i = n - 1; i >= 0; i--) {
			for (int j = i + 1; j < n; j++) {
				dp[i][j] = max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
			}
		}
		return dp[0][n - 1] >= 0;
	}
};
// @lc code=end

