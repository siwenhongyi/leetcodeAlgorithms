/*
* @lc app=leetcode.cn id=1178 lang=cpp
*
* [1178] 猜字谜
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
private:
	unordered_map<int, int> book;
	vector<int> res;
public:
	vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
		int n = words.size(), m = puzzles.size(), i, j, k;
		res.resize(m,0);
		i = 0;
		while (i < n) {
			for (j = k = 0; j < words[i].size(); j++)
				k |= 1 << (words[i][j] - 'a');
			book[k]++;
			i++;
		}
		i = 0;
		while (i<m)
		{
			for (j = k = 0; j <puzzles[i].size(); j++)
				k |= 1 << (puzzles[i][j] - 'a');
			j = k;
			while (j)
			{
				if (j >> (puzzles[i][0] - 'a') & 1)
					res[i] += book[j];
				j = j - 1 & k;
			}
			i++;
		}
		return res;
	}
};

// @lc code=end

