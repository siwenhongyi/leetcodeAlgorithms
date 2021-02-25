/*
* @lc app=leetcode.cn id=830 lang=cpp
*
* [830] 较大分组的位置
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
public:
	vector<vector<int>> largeGroupPositions(string S) {
		vector<vector<int> > res;
		int n = S.size();
		int i = 0;
		while(i < n) {
			int j = i + 1;
			while (j<n&&S[i]==S[j])
				j++;
			if (j - i >= 3)
				res.push_back({ i,j - 1 });
			i = j;
		}
		return res;
	}
};

// @lc code=end

