/*
* @lc app=leetcode.cn id=781 lang=cpp
*
* [781] 森林中的兔子
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
public:
	int numRabbits(vector<int>& v) {
		map<int, int> p;
		for (auto& i : v)
			p[i]++;
		int res = 0;
		for (auto i : p) {
			while (i.second > i.first + 1) {
				res += i.first + 1;
				i.second -= (i.first + 1);
			}
			res += i.first+1;
		}
		return res;
	}
};

// @lc code=end

