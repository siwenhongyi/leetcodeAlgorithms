/*
* @lc app=leetcode.cn id=1222 lang=cpp
*
* [1222] 可以攻击国王的皇后
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
public:
	int g[8][8];
	int fx[8] = { 1,1,0,-1,-1,-1,0,1 }, fy[8] = { 0,-1,-1,-1,0,1,1,1 };


	vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
		int x = king.front(), y = king.back(), n = queens.size();
		int cou = 8, newx, newy, flag;
		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++)
				g[i][j] = 1;
		for (auto& i : queens)
			g[i.front()][i.back()] = 3;
		vector<bool> top(8, true);
		vector<vector<int> > res;
		queue<pair<int, int>> q;
		q.push(make_pair(x, y));
		g[x][y] = 0;
		while (cou&& q.size()) {
			auto qa = q.front();
			q.pop();
			for (int i = 0; i < 8; i++) {
				newx = qa.first + fx[i], newy = qa.second + fy[i];
				flag = 0;
				if (newx >= 0 && newx < 8 && newy >= 0 && newy < 8&&g[newx][newy]) {
					if (g[newx][newy] == 3) {
						if (newx == x) {
							if (newy > y&& top[0]) {
								flag = 1;
								top[0] = false;
							}
							else if (newy < y && top[4]) {
								flag = 1;
								top[4] = false;
							}								
						}
						else if (newy == y) {
							if (newx < x && top[2]) {
								flag = 1;
								top[2] = false;
							}
							else if (newx > x&& top[6]) {
								flag = 1;
								top[6] = false;
							}
						}
						else if (abs(x - newx) == abs(y - newy)) {
							if (newx<x && y<newy&& top[1]) {
								flag = 1;
								top[1] = false;
							}
							else if (newx<x && y>newy&& top[3]) {
								flag = 1;
								top[3] = false;
							}
							else if (newx > x&& newy > y&& top[7]) {
								flag = 1;
								top[7] = false;
							}
							else if (newx > x&& newy < y && top[5]) {
								flag = 1;
								top[5] = false;
							}
						}
					}
					if (flag)
						res.push_back({ newx,newy });
					g[newx][newy] = 0;
					q.push(make_pair(newx, newy));
					cou = count(top.begin(), top.end(), true);
				}
			}
		}
		return res;
	}
};

// @lc code=end

