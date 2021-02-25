/*
* @lc app=leetcode.cn id=1104 lang=cpp
*
* [1104] 二叉树寻路
*/

#include"head.h"
using namespace std;
// @lc code=start
#include<vector>
#include <iostream>
using namespace std;


class Solution {
public:
	vector<int> pathInZigZagTree(int label) {
		if (label == 1) {
			vector<int> res = { 1 };
			return res;
		}
		vector<int> res;
		int h = 0, n = 1;
		for (int i = 1;; i++) 
			if (label > 2 * n - 1) 
				n *= 2;
			else {
				h = i;
				break;
			}
		res.push_back(label);
		while (h) {
			int c = 1;
			label = *(res.end() - 1);
			for (int i = int(pow(2, h - 1)) + 2;; i += 2) {
				if (label >= i)
					c++;
				else
					break;

			}
			res.push_back(int(pow(2, h - 1) - c));
			h--;
		}
		res.pop_back();

		vector<int> t;
		for (auto iter = res.rbegin(); iter != res.rend(); iter++)
			t.push_back(*iter);

		return t;
	}
};

// @lc code=end

