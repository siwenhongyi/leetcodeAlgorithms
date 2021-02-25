/*
* @lc app=leetcode.cn id=932 lang=cpp
*
* [932] 漂亮数组
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
	vector<int> beautifulArray(int N) {
		if (N == 1) return { 1 };
		if (N == 2) return { 1, 2 };
		if (N == 3) return { 1, 3, 2 };
		if (N == 4) return { 1, 3, 2, 4 };
		vector<int> res = { 1,3,2,4 };
		while (res.size() <= N)
		{
			for (unsigned int i = 0; i < res.size(); i++)
				res[i] *= 2;
			int t = res.size();
			for (auto i = 0; i < t; i++)
				res.push_back(res[i] - 1);
		}
		auto it = res.begin();
		while (it!=res.end()){
			if (*it > N)
				it = res.erase(it);
			else
				it++;
		}
		return res;
	}
};
// @lc code=end

