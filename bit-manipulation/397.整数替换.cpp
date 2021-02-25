/*
* @lc app=leetcode.cn id=397 lang=cpp
*
* [397] 整数替换
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
	int integerReplacement(int n) {
		if (n == 1)
			return 0;
		if (n % 2) {
			long long x = n;
			return 2 + min(integerReplacement((x + 1) / 2), integerReplacement((x - 1) / 2));
		}
		else
			return 1 + integerReplacement(n / 2);
	}
};

// @lc code=end

