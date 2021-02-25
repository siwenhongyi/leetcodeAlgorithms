/*
* @lc app=leetcode.cn id=387 lang=cpp
*
* [387] 字符串中的第一个唯一字符
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
public:
	int firstUniqChar(string s) {
		vector<int> ch(26, 0);
		int n = s.size();
		char c;
		for (int i = 0; i < n;i++) {
			c = s[i];
			ch[c - 'a']++;
		}
		for (int i = 0; i < n; i++)
			if (ch[s[i]-'a'] == 1)
				return i;
		return -1;

	}
};

// @lc code=end

