/*
* @lc app=leetcode.cn id=442 lang=cpp
*
* [442] 数组中重复的数据
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
	vector<int> findDuplicates(vector<int>& nums) {
		if (nums.size() <= 1)
			return {};
		vector<int> res;
		unsigned int i = 1;
		for (auto i : nums) {
			if (nums[abs(i) - 1] > 0)
				nums[abs(i) - 1] *= -1;
			else
				res.push_back(abs(i));
		}
		return res;
	}
}; 

// @lc code=end

