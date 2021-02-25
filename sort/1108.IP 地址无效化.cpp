/*
* @lc app=leetcode.cn id=1108 lang=cpp
*
* [1108] IP 地址无效化
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
public:
	string defangIPaddr(string address) {
	auto iter = address.begin();
	for (; iter != address.end(); iter++) 
		if(*iter=='.'){
			iter = address.insert(iter, '[');
			iter = address.insert(iter+2, ']');
	}
		return address;

	}
};

// @lc code=end

