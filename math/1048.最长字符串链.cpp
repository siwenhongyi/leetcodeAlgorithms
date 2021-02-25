/*
* @lc app=leetcode.cn id=1048 lang=cpp
*
* [1048] 最长字符串链
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
public:
	bool check(const string &s, const string &t) {
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == t[i])
				continue;
			int j = i + 1;
			while (i < s.size() && s[i] == t[j]) {
				i++;
				j++;
			}
			if (i == s.size())
				return true;
			else
				return false;
		}
		return true;
	}

	int longestStrChain(vector<string>& words) {
		int res = 0, n = words.size();
		if (n <= 1)
			return words.size();
		sort(words.begin(), words.end(), [](const string &s, const string &t) {return s.size() < t.size(); });
		vector<int> dp(n, 1), size;

		for (auto &i : words) {
			sort(i.begin(), i.end());
			size.push_back(i.size());
		}
		
		for (int i = 1; i < n; i++) {
			for (int j = 0; j < i; j++)
				if (size[j] + 1 == size[i]&&check(words[j],words[i]))
					dp[i] = max(dp[i], dp[j] + 1);
			res = max(res, dp[i]);
		}
		return res;
	}
};

// @lc code=end

