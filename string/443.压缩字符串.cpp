/*
* @lc app=leetcode.cn id=443 lang=cpp
*
* [443] 压缩字符串
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
public:
	int compress(vector<char>& s) {
		if (s.size() <= 1)
			return s.size();
		string t;
		int index = 0;
		int i = 0, cou, j, n = s.size();
		while(i < n) {
			cou = 0;
			j = i;
			while (j < n && s[i] == s[j]){
                j++;
				cou++;
            }
			s[index++] = s[i];
            if(cou>1){
			t = to_string(cou);
			for (auto& i : t)
				s[index++] = i;
            }
			i = j;
		}
		s.resize(index);
		return index;
	}
};

// @lc code=end

