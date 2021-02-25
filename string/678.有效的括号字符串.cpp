/*
* @lc app=leetcode.cn id=678 lang=cpp
*
* [678] 有效的括号字符串
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
	bool checkValidString(string s) {
		if (!s.size())
			return true;
		int left = 0, x = 0;
		for (auto i : s) {
			if (i == '(') {
				left++;
				x++;
			}
			else {
				if (left > 0)
					left--;
				if (i == ')')
					x--;
				else
					x++;	
			}
			if (x < 0)
				return false;
		}
		return left == 0;
	}
};
// @lc code=end

