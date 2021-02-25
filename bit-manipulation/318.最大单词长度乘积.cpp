/*
* @lc app=leetcode.cn id=318 lang=cpp
*
* [318] 最大单词长度乘积
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
public:
	int maxProduct(vector<string>& words) {
		vector<int> len, key;
		int res, t, n = words.size();
		for (auto& c : words) {
			len.push_back(c.size());
			t = 0;
			for (auto& ch : c)
				t |= (1 << (ch - 'a'));
			key.push_back(t);
		}
		res = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if ((key[i] & key[j]) == 0)
					res = max(res, len[i] * len[j]);
			}
		}
		return res;
	}
};
// @lc code=end

