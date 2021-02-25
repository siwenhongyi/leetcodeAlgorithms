/*
* @lc app=leetcode.cn id=10 lang=cpp
*
* [10] 正则表达式匹配
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
public:
	bool isMatch(string s, string p) {
		if (!p.size())
			return !s.size();
		if (p.size() && p[0] == '*')
			return false;
		int size_s = s.size(), size_p = p.size();
		vector<vector<bool>> pos(size_s + 1, vector<bool>(size_p + 1, false));
		pos[0][0] = true;
		for (int i = 0; i < size_p; i++)
			if (p[i] == '*'&&pos[0][i - 1])
				pos[0][i + 1] = true;
		for (int i = 0; i < size_s; i++) {
			for (int j = 0; j < size_p; j++) {
				if (s[i] == p[j] || p[j] == '.')
					pos[i + 1][j + 1] = pos[i][j];
				else if (p[j] == '*') {
					if (p[j - 1] != s[i])
						pos[i + 1][j + 1] = pos[i + 1][j - 1];
					if (p[j - 1] == s[i] || p[j - 1] == '.')
						pos[i + 1][j + 1] = pos[i][j + 1] || pos[i + 1][j] || pos[i + 1][j - 1];
				}
			}
		}
		return pos[size_s][size_p];
	}
};

// @lc code=end

