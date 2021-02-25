/*
* @lc app=leetcode.cn id=70 lang=cpp
*
* [70] 爬楼梯
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
	int climbStairs(int n) {
		if (!n)
			return 0;
		vector<int> res = { 1,2 };
		for (int i = 3; i <= n; i++) 
			res.push_back(res[i - 3] + res[i - 2]);
		return res[n - 1];
	}
};
// @lc code=end

