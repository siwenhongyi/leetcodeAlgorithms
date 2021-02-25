/*
* @lc app=leetcode.cn id=1663 lang=cpp
*
* [1663] 具有给定数值的最小字符串
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
public:
	string getSmallestString(int n, int k) {
		string res(n, 'a');
		k -= n--;
		while (k) {
			int t = min(k, 25);
			res[n--] += t;
			k -= t;
		}
		return res;
	}
};
// @lc code=end

