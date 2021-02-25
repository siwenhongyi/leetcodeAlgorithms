/*
* @lc app=leetcode.cn id=1243 lang=cpp
*
* [1243] 数组变换
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
public:
	vector<int> transformArray(vector<int>& arr) {
		if (arr.size() <= 3)
			return arr;
		vector<int> t(arr);
		int i,flag = 1;
		while (flag) {
			flag = 0;
			for(i = 1;i<arr.size()-1;i++)
				if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
					flag++;
					t[i]--;
				}
				else if (arr[i] < arr[i - 1] && arr[i] < arr[i + 1]) {
					flag++;
					t[i]++;
				}
			arr = t;
		}
		return arr;
	}
};
// @lc code=end

