/*
* @lc app=leetcode.cn id=74 lang=cpp
*
* [74] 搜索二维矩阵
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
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.size() == 0 || matrix.back().size() == 0)
			return false;
		int m = matrix.size(), n = matrix[0].size();
		int left = 0, right = m * n - 1;
		while (left <= right) {
			int mid = (left + right) / 2;
			int x = (mid / n), y = (mid % n);
			if (matrix[x][y] == target)
				return true;
			else if (target < matrix[x][y])
				right = mid - 1;
			else
				left = mid + 1;
		}
		return false;
	}
};

// @lc code=end

