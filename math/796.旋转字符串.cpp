/*
* @lc app=leetcode.cn id=796 lang=cpp
*
* [796] 旋转字符串
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
	bool rotateString(string A, string B) {
		if (A.size() != B.size())
			return false;
		else if (A == B)
			return true;
		else if (A.size() == 1)
			return false;
		A += A;
		int t = B.size();
		for (unsigned int i = 0; i < B.size();i++) {
			string s(A.begin() + i, A.begin() + i + t);
			if (s == B)
				return true;
		}
		return false;


		//int t = A.size();
		//while (t--){
		//	A.push_back(A.front());
		//	A.erase(A.begin());
		//	if (A == B)
		//		return true;
		//}
		//return false;
	}
};
// @lc code=end

