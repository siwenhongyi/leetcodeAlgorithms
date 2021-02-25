/*
* @lc app=leetcode.cn id=31 lang=cpp
*
* [31] 下一个排列
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
	void nextPermutation(vector<int>& nums) {
		if (nums.size() <= 1)
			return;
		bool t = false;
		int index = nums.size() - 2;
		while (index >= 0 && nums[index] >= nums[index + 1])
			index--;
		if (index >= 0) {
			int j = nums.size() - 1;
			while (j >= 0 && nums[j] <= nums[index])
				j--;
			swap(nums[index], nums[j]);
		}
		reverse(nums.begin() + index + 1, nums.end());
	}
};

// @lc code=end

