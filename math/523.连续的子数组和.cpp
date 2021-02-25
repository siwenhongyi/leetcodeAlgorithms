/*
* @lc app=leetcode.cn id=523 lang=cpp
*
* [523] 连续的子数组和
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
public:
	bool checkSubarraySum(vector<int>& nums, int k) {
		unsigned int size = nums.size();
		vector<int> sum(1, 0);
		for (unsigned int i = 0; i < size; i++)
			sum.push_back(sum[i] + nums[i]);
		for (unsigned int i = 0; i < size - 1; i++)
			for (unsigned int j = i + 1; j < size; j++) {
				if (!k&&!(sum[j + 1] - sum[i])) 
					return true;
				else if (k && (sum[j + 1] - sum[i]) % k == 0)
					return true;
			}
		return false;
	}
};

// @lc code=end

