/*
* @lc app=leetcode.cn id=1176 lang=cpp
*
* [1176] 健身计划评估
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
public:
	int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {
		int res = 0;
		for (int i = 0; i < calories.size()-k+1; i ++) {
			int sum = 0;
			for (int j = 0; i + j < calories.size() && j < k; j++)
				sum += calories[i + j];
			if (sum > upper)
				res++;
			if (sum < lower)
				res--;
		}
		return res;
	}
};

// @lc code=end

