/*
* @lc app=leetcode.cn id=565 lang=cpp
*
* [565] 数组嵌套
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
	int arrayNesting(vector<int>& nums) {
		int res = 0;
		if (!nums.size())
			return res;
		vector<bool> visited(nums.size(), false);
		int pre, n = nums.size();
		for (auto i : nums) {
			int index = i;
			int t = 0;
			while (!visited[index])
			{
				t++;
				visited[index] = true;
                index= nums[index];
			}
			if (t > res)
				res = t;
		}
		return res;
	}
};

// @lc code=end

