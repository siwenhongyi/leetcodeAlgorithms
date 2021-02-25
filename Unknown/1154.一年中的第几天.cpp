/*
* @lc app=leetcode.cn id=1154 lang=cpp
*
* [1154] 一年中的第几天
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
	int yue(int y, int m) {
		switch (m)
		{
		case 1:case 3:case 5:case 7:case 8:case 10:case 12:
			return 31;
			break;
		case 2:
			return 28 + ((y % 100 != 0 && y % 4 == 0) || y % 400 == 0);
			break;
		case 4:case 6:case 9:case 11:
			return 30;
			break;
		}
		return 0;
	}
	int ordinalOfDate(string date) {
		string t(date.begin(), date.begin() + 4);
		int y = atoi(t.c_str());
		t.clear();
		t.insert(t.end(), date.begin() + 5, date.begin() + 7);
		int m = atoi(t.c_str());
		t.clear();
		t.insert(t.end(), date.begin() + 8, date.end());
		int d = atoi(t.c_str());

		int res = 0;
		for (int i = 1; i < m; i++) 
			res += yue(y, i);
		res += d;
		return res;



	}
};
// @lc code=end

