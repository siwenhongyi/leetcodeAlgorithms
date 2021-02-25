/*
* @lc app=leetcode.cn id=1138 lang=cpp
*
* [1138] 字母板上的路径
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
#define maxn 65535

struct Node
{
	int x, y;
}node[26];
class Solution {
public:
	string alphabetBoardPath(string target) {
		int x = 0, y = 0;
		for (int i = 0; i < 26; i++) {
			node[i].x = x;
			node[i].y = y++;
			if (y > 4) {
				x++;
				y = 0;
			}
		}

		int nx = 0, ny = 0;
		int fx, fy;
		string res;
		for (unsigned int i = 0; i < target.size(); i++) {
			int flag = 0;
			x = target[i] - 'a';
			fx = node[x].x - nx;
			fy = node[x].y - ny;
			if (fx != 0) {
				char c = fx > 0 ? 'D' : 'U';
				for (int j = 0; j < abs(fx); j++)
					res.push_back(c);
			}
			if (x == 25 && ny != 0) {
				flag = 1;
				res.pop_back();
			}
			if (fy != 0) {
				char c = fy > 0 ? 'R' : 'L';
				for (int j = 0; j < abs(fy); j++)
					res.push_back(c);
			}
			if (flag)
				res.push_back('D');
			res.push_back('!');
			nx = node[x].x;
			ny = node[x].y;
			}
		return res;
	}
};

// @lc code=end

