/*
* @lc app=leetcode.cn id=150 lang=cpp
*
* [150] 逆波兰表达式求值
*/

#include"head.h"
using namespace std;
// @lc code=start
#include<list>
#include<queue>
#include<unordered_map>
#include<string>
#include<unordered_set>
#include<iomanip>
#include<math.h>
#include<set>
#include<map>
#include<vector>
#include<algorithm>
#include<string>
#include <iostream>
using namespace std;

class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		if (tokens.size() == 1)
			return atoi(tokens[0].c_str());
		vector<int> res;
		char op[4] = { '+','-','*','/' };
		for (auto i : tokens) {
			if (i.size() == 1&&(i[0]<'0'||i[0]>'9')) {
				int y = res.back();
				res.pop_back();
				int x = res.back();
				res.pop_back();
				switch (i[0])
				{
				case '+':
					x += y;
					break;
				case '-':
					x -= y;
					break;
				case '*':
					x *= y;
					break;
				case '/':
					x /= y;
					break;
				}
				res.push_back(x);
				continue;
			}
			res.push_back(atoi(i.c_str()));
		}
		return res.front();
	}
};
// @lc code=end

