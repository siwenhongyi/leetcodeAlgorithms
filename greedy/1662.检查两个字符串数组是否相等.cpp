/*
* @lc app=leetcode.cn id=1662 lang=cpp
*
* [1662] 检查两个字符串数组是否相等
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
public:
	bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
		string a, b;
		for (auto& it : word1)a += it;
		for (auto& it : word2)b += it;
		return a == b;
	}
};
// @lc code=end

