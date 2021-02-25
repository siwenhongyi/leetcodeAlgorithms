/*
* @lc app=leetcode.cn id=171 lang=cpp
*
* [171] Excel表列序号
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
public:
	int titleToNumber(string s) {
		int res = 0;
		int i = 0;
		for (auto it = s.rbegin(); it != s.rend(); it++) {
			res += (*it - 'A' + 1)*pow(26, i++);
		}
		return res;
	}
};

// @lc code=end

