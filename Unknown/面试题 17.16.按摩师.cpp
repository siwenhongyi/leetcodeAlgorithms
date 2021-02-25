/*
* @lc app=leetcode.cn id=面试题 17.16 lang=cpp
*
* [面试题 17.16] 按摩师
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
public:
	int massage(vector<int>& arr) {
		int n = arr.size();
		if (!n)
			return 0;
		else if (n == 1)
			return arr.front();
		else if (n == 2)
			return arr[0] > arr[1] ? arr[0] : arr[1];
		vector<int> dp(n, 0);
        dp[0]=arr[0];
        dp[1]=max(arr[0],arr[1]);
		int res = -1;
		for (int i = 2; i < n; i++) {
			dp[i] = max(dp[i - 1], dp[i - 2] + arr[i]);
			res = max(res, dp[i]);
		}
		return res;
	}
}; 

// @lc code=end

