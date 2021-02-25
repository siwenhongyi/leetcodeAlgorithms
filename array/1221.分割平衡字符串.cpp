/*
* @lc app=leetcode.cn id=1221 lang=cpp
*
* [1221] 分割平衡字符串
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
public:
	int balancedStringSplit(string s) {
		int res = 0, left, right, n = s.size();
		left = right = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == 'L')
				left++;
			else
				right++;
			if (left && right && left == right) {
				res++;
				left = right = 0;
			}
		}
		return left==right&&left==0?res:1;
	}
};

// @lc code=end

