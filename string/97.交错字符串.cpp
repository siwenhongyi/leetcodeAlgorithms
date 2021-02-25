/*
* @lc app=leetcode.cn id=97 lang=cpp
*
* [97] 交错字符串
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
public:
	bool isInterleave(string s1, string s2, string s3) {
		int n = s1.size(), m = s2.size(), k = s3.size();
		if (n + m != k)
			return false;
		vector<vector<bool> > v(n + 1, vector<bool>(m + 1, false));
		v[0][0] = true;
		int i = 1;
		while (i <= m) {
			v[0][i] = v[0][i - 1] && (s2[i - 1] == s3[i - 1]);
			i++;
		}
		i = 1;
		while (i <= n) {
			v[i][0] = v[i - 1][0] && (s1[i - 1] == s3[i - 1]);
			i++;
		}
		for (i = 1; i <= n; i++) 
			for (int j = 1; j <= m; j++) 
				v[i][j] = (v[i - 1][j] && s1[i - 1] == s3[i + j - 1]) || (v[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
			
		return v.back().back();
	}
};

// @lc code=end

