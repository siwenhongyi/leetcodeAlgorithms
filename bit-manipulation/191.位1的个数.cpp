/*
* @lc app=leetcode.cn id=191 lang=cpp
*
* [191] 位1的个数
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
	int hammingWeight(uint32_t n) {
		int res = 0;
		while (n)
		{
			if (n % 2)
				res++;
			n /= 2;
		}
		return res;
	}
};
// @lc code=end

