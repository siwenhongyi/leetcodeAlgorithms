/*
* @lc app=leetcode.cn id=1175 lang=cpp
*
* [1175] 质数排列
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
public:
	int fun(int n) {
		vector<bool> s(n + 1, true);
		int cou = 0;
		for (int i = 2; i <= n; i++) {
			if (s[i]) {
				cou++;
				for (int j = i + i; j <= n; j += i)
					s[j] = false;
			}
		}
		return cou;
	}
	long long int f(int n) {
		if (n == 1)
			return 1;
		return ((n % 1000000007) * (f(n - 1) % 1000000007)) % 1000000007;
	}
	int numPrimeArrangements(int n) {
        if(n<=2)
            return 1;
		int a = fun(n);
		int b = n - a;
		long long int x = f(a), y = f(b);
		return ((x % 1000000007)*(y % 1000000007)) % 1000000007;
	}
};

// @lc code=end

