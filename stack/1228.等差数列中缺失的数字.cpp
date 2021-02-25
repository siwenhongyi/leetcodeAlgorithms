/*
* @lc app=leetcode.cn id=1228 lang=cpp
*
* [1228] 等差数列中缺失的数字
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
public:
	int missingNumber(vector<int>& arr) {
		int x, y, n = arr.size();
		int d;
		x = arr[1] - arr[0], y = arr[n - 1] - arr[n - 2];
		d = abs(x) < abs(y) ? x : y;
		for (int i = 1; i < n; i++) {
			if (arr[i] != arr[i - 1] + d)
				return arr[i - 1] + d;
		}
		return 0;
	}
};
// @lc code=end

