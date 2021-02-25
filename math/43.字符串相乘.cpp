/*
* @lc app=leetcode.cn id=43 lang=cpp
*
* [43] 字符串相乘
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
	string multiply(string num1, string num2) {
		if (num1 == "0" || num2 == "0")
			return "0";
		string res;
		for (int i = num2.length()-1; i >=0; i--) {
			string t;
			int x = num2[i] - '0';
			int r = 0;
			for (int j = num1.length() - 1; j >= 0; j--) {
				int y = (num1[j] - '0')*x + r;
				r = y / 10;
				t.insert(t.begin(), '0' + (y % 10));
			}
			if (r)
				t.insert(t.begin(), '0' + r);
			for (int k = 0; k < num2.length() - i - 1; k++)
				t.push_back('0');
			r = 0;
			int j, k;
			if (res.size() > 0) {
				while (res.length() != t.length())
					res.insert(res.begin(), '0');
				for (j = t.length() - 1, k = res.length() - 1; j >= 0 && k >= 0; j--, k--) {
					x = (t[j] - '0') + (res[k] - '0') + r;
					res[k] = '0' + x % 10;
					r = x / 10;
				}
				if (r)
					res.insert(res.begin(), '1');
			}
			else
				res = t;
		}
		return res;
	}
};

// @lc code=end

