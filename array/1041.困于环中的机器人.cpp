/*
* @lc app=leetcode.cn id=1041 lang=cpp
*
* [1041] 困于环中的机器人
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
public:
	bool isRobotBounded(string instructions) {
		instructions = instructions + instructions + instructions + instructions;
		int x[2] = { 0,0 };
		int t = 1;
		for (int i = 0; i < instructions.length(); i++) {
			if (instructions[i] == 'G') {
				switch (t)
				{
				case 1:
					x[1]++;
					break;
				case 3:
					x[1]--;
					break;
				case 4:
					x[0]--;
					break;
				case 2:
					x[0]++;
					break;
				default:
					break;
				}
				continue;
			}
			if (instructions[i] == 'L') {
				t = t == 1 ? 4 : --t;
				continue;
			}
			else 
				t = t == 4 ? 1 : ++t;
		}
		if (x[0] == 0 && x[1] == 0)
			return true;
		else
			return false;
	}
};

// @lc code=end

