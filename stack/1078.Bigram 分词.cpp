/*
* @lc app=leetcode.cn id=1078 lang=cpp
*
* [1078] Bigram 分词
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
public:
	vector<string> findOcurrences(string s, string first, string second) {
		if (s.empty())
			return {};
		vector<string> res;
		int index = 0, n = s.size();
		int i, j;
		while (index < n) {
			if (s[index] == ' ')
				continue;
			i = index;
			while (i< n && s[i] != ' ')
				i++;
            if(i==n)
                return res;
			j = i;
			if (s.substr(index, i - index) == first) {
				index = ++i;
				while (i < n && s[i] != ' ')
					i++;
                if(i==n)
                    return res;
				if (s.substr(index, i - index) == second) {
					index = ++i;
					while (i < n && s[i] != ' ')
						i++;
                    if(i==n){
                        res.push_back(s.substr(index));
                        return res;
                    }
					res.push_back(s.substr(index, i - index));
				}
			}
			index = j + 1;
		}
		return res;
	}
};
// @lc code=end

