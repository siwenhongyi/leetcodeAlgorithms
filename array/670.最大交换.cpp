/*
* @lc app=leetcode.cn id=670 lang=cpp
*
* [670] 最大交换
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
public:
	int maximumSwap(int num) {
		string s = to_string(num);
		if (s.size() <= 1)
			return num;
		vector<char> pos(s.begin(), s.end());
		sort(pos.begin(), pos.end(), greater<int>());
		for (unsigned int i = 0; i < s.size(); i++)
			if (s[i] != pos[i]) {
				int x = s.size() - 1;
				while (x < s.size() && s[x] != pos[i])
					x--;
				swap(s[i], s[x]);
				break;
			}
		return atoi(s.c_str());
	}
};

// @lc code=end

