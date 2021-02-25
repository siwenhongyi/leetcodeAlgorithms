/*
* @lc app=leetcode.cn id=1003 lang=cpp
*
* [1003] 检查替换后的词是否有效
*/

#include"head.h"
using namespace std;
// @lc code=start
#include<list>
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
	bool isValid(string S) {
		if (S.length() % 3 != 0)
			return false;
		for (unsigned int i = 0; i < S.length();) {
			if (i + 2 < S.length() && S[i] == 'a'&&S[i + 1] == 'b'&&S[i + 2] == 'c') {
				S.erase(S.begin() + i, S.begin() + i + 3);
				i = 0;
			}
			else
				i++;
		}
		return !S.length();
	}
};

// @lc code=end

