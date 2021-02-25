/*
* @lc app=leetcode.cn id=1190 lang=cpp
*
* [1190] 反转每对括号间的子串
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
private:
	string res;
	int n;
public:
	int dfs(int i) {
		int index = i + 1;
		while (index < n) {
			if (res[index] == ')') {
				reverse(res.begin() + i + 1, res.begin() + index);
				return index + 1;
			}
			else if (res[index] == '(')
				index = dfs(index);
			else
				index++;
		}
		return index;
	}


	string reverseParentheses(string s) {
		string ans;
		res = s;
		int i = 0;
		n = s.size();
		while (i<n){
			if (res[i] == '(')
				i = dfs(i);
			else
				i++;
		}

		for (auto it : res)
			if (it != '(' && it != ')')
				ans.push_back(it);

		return ans;
	}
};

// @lc code=end

