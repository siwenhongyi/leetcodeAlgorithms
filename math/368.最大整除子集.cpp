/*
* @lc app=leetcode.cn id=368 lang=cpp
*
* [368] 最大整除子集
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
	vector<int> largestDivisibleSubset(vector<int>& nums) {
		if (nums.size() == 0)
			return nums;
		sort(nums.begin(), nums.end());
		vector<int> pre(nums.size()),q(nums.size());
		int max = 1, index= 0;
		for (unsigned int i = 0; i < nums.size(); i++) {
			if (i == 0) {
				pre[i] = -1;
				q[i] = 1;
				continue;
			}
			int p = -1, len = 1;
			for (int j = i; j >= 0; j--)
				if (nums[i] % nums[j] == 0 && q[j] + 1 > len) {
					p = j;
					len = q[j] + 1;
				}
			pre[i] = p;
			q[i] = len;
			if (len > max){
                max = len;
				index = i;
            }
		}
		vector<int> res;
		while (index!=-1)
		{
			res.push_back(nums[index]);
			index = pre[index];
		}
		return res;
	}
};

// @lc code=end

