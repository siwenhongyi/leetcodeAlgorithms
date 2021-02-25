/*
* @lc app=leetcode.cn id=747 lang=cpp
*
* [747] 至少是其他数字两倍的最大数
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
	int dominantIndex(vector<int>& nums) {
		vector<int> temp(nums.begin(), nums.end());
		sort(temp.begin(), temp.end());
		int m = temp.back();
		for (unsigned int i = 0; i < temp.size() - 1; i++)
			if (2 * temp[i] > m)
				return -1;
		return find(nums.begin(), nums.end(), m) - nums.begin();
	}
};

// @lc code=end

