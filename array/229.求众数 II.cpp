/*
* @lc app=leetcode.cn id=229 lang=cpp
*
* [229] 求众数 II
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
public:
	vector<int> majorityElement(vector<int>& nums) {
		int n = nums.size() / 3;
		map<int, int> pos;
		vector<int> res;
		for (auto i : nums) {
			if (++pos[i]>n) {
				res.push_back(i);
				pos[i] = -1000000;
			}
		}
		return res;
	}
};

// @lc code=end

