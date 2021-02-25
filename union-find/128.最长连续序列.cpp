/*
* @lc app=leetcode.cn id=128 lang=cpp
*
* [128] 最长连续序列
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
	int longestConsecutive(vector<int>& nums) {
		if (nums.size() < 2)
			return nums.size();
		set<int> t(nums.begin(), nums.end());
		vector<int> pos(t.begin(), t.end());
		int res = 0, i = 0;
		while(i<pos.size()) {
			int len = 0;
			int j = i + 1;
			while (j < pos.size() && pos[j] ==pos[j - 1] + 1)
				j++;
			if (j - i > res)
				res = j - i;
			i = j;
			}
		return res;
		}
};
// @lc code=end

