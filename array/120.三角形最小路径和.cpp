/*
* @lc app=leetcode.cn id=120 lang=cpp
*
* [120] 三角形最小路径和
*/

#include"head.h"
using namespace std;
// @lc code=start
#include<list>
#include<queue>
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

class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		if (!triangle.size())
			return 0;
		else if (triangle.size() == 1)
			return triangle[0][0];
		for (int i = triangle.size()-1; i > 0; i--) {
			int x = 0;
			for (int j = 0; j <= triangle[i].size() - 2; j++) {
				int t = min(triangle[i][j], triangle[i][j + 1]);
				triangle[i - 1][x++] += t;
			}
		}
		return triangle[0][0];
	}
};
// @lc code=end

