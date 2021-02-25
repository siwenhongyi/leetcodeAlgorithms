/*
* @lc app=leetcode.cn id=119 lang=cpp
*
* [119] 杨辉三角 II
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
public:
	vector<int> getRow(int r) {
		if (r == 0)
			return { 1 };
		if (r == 1)
			return { 1,1 };
		vector<int> q(2,1), p;
		int len = 1, n;
		while (len < r) {
			n = q.size();
			p.push_back(1);
			for (int i = 1; i < n; i++) 
				p.push_back(q[i] + q[i - 1]);
			p.push_back(1);
			q.swap(p);
			p.clear();
			len++;
		}
		return q;
	}
};
// @lc code=end

