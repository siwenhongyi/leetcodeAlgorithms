/*
* @lc app=leetcode.cn id=415 lang=cpp
*
* [415] 字符串相加
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
public:
	string addStrings(string s, string ss) {
		if (s.size() < ss.size())
			s.swap(ss);
		int i = s.size()-1, j=ss.size()-1,t=0;
		while(i >= 0||j>=0) {
            if(i>=0)
			t += s[i] - '0';
            if(j>=0)
                t+=ss[j--] - '0';
			s[i--] = '0' + t%10;
            t/=10;
		}
      	if (t)
			s.insert(s.begin(), '1');  
		while (s.front() == '0'&&s.size()>1)
			s.erase(s.begin());
		return s;
	}
};

// @lc code=end

