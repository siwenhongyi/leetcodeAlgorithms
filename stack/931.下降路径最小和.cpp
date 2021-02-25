/*
* @lc app=leetcode.cn id=931 lang=cpp
*
* [931] 下降路径最小和
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
	int minFallingPathSum(vector<vector<int>>& A) {
		if (A.size() == 1)
			return A[0][0];
		int len = A.size();
		for (int i = len - 1; i > 0; i--)
			for (int j = 0; j < len; j++) {
				int k = -1;
				int m = INT_MAX;
				while (k<=1)
				{
					int t = j - k;
					if (t >= 0 && t < len&&A[i][t] < m)
						m = A[i][t];
					k++;
				}
				A[i - 1][j] += m;
			}
		int res = INT_MAX;
		for (int i = 0; i < len; i++) {
			if (res > A[0][i])
				res = A[0][i];
		}
		return res;
	}
};

// @lc code=end

