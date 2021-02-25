/*
* @lc app=leetcode.cn id=921 lang=cpp
*
* [921] 使括号有效的最少添加
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
public:
	int minAddToMakeValid(string S) {
		if (S.length() == 0)
			return 0;
		int left = 0, right = 0;
		for (auto i : S) {
			if (i == '(')
				left++;
			else {
				if (left > 0)
					left--;
				else
					right++;
			}
		}
		return left + right;
	}
};

// @lc code=end

