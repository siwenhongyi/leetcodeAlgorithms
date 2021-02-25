/*
* @lc app=leetcode.cn id=1189 lang=cpp
*
* [1189] “气球” 的最大数量
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
public:
	int maxNumberOfBalloons(string text) {
		vector<double> pos(5, 0);

		for (auto it : text) {
			if (it == 'b')
				pos[0] += 1;
			else if (it == 'a')
				pos[1] += 1;
			else if (it == 'l')
				pos[2] += 0.5;
			else if (it == 'o')
				pos[3] += 0.5;
			else if (it == 'n')
				pos[4] += 1;
		}
		return *min_element(pos.begin(), pos.end());
	}
};

// @lc code=end

