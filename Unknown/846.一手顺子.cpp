/*
* @lc app=leetcode.cn id=846 lang=cpp
*
* [846] 一手顺子
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
public:
	bool isNStraightHand(vector<int>& v, int W) {
		if (W == 1)
			return true;
		map<int, int> pos;
		for (auto& i : v)
			pos[i]++;
		auto it = pos.begin();
		while(it != pos.end()) {
			it->second--;
			auto iter = ++it;
			it--;
			int len = 1;
			while (iter != pos.end() && len <= W - 1)
				if (iter->second && iter->first == it->first + len) {
					iter->second--;
					len++;
					iter++;
				}
				else
					return false;
			if (len != W)
				return false;
			while (it != pos.end() && !it->second)
				it++;
		}
		return true;
	}
};

// @lc code=end

