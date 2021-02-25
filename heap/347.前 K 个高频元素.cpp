/*
* @lc app=leetcode.cn id=347 lang=cpp
*
* [347] 前 K 个高频元素
*/

#include"head.h"
using namespace std;
// @lc code=start
typedef pair<int, int> pp;

class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		vector<int> res;
		map<int, int> p;
		priority_queue<pp, vector<pp>,less<pp>> q;
		for (auto& i : nums)
			p[i]++;
		for (auto& i : p) {
			q.push(make_pair(i.second,i.first));		
		}
		while (res.size()!=k) {
			res.push_back(q.top().second);
			q.pop();
		}
		return res;
	}
};
// @lc code=end

