/*
* @lc app=leetcode.cn id=829 lang=cpp
*
* [829] 连续整数求和
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
	int consecutiveNumbersSum(int N) {
        if(N<=2)
            return 1;
		int num = 1;
		int n = 2 * N;
		for (int i = 2; i <= sqrt(n); i++) {
			if (n%i == 0) {
				int end = (n / i + i - 1) / 2;
				int start = end - n / i + 1;
				if ((start + end)*(end - start + 1) == n)
					num++;
			}
		}
		return num;
	}
};

// @lc code=end

