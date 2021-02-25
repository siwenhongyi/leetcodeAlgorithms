/*
* @lc app=leetcode.cn id=125 lang=cpp
*
* [125] 验证回文串
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
public:
	bool isPalindrome(string s) {
		string res, t;
		for (auto &it : s) {
			if (isdigit(it) || isalpha(it))
				res.push_back(tolower(it));
		}
        t.resize(res.size());
		reverse_copy(res.begin(), res.end(), t.begin());
        //cout<<res<<' '<<t<<endl;
		return res == t;
	}
};

// @lc code=end

