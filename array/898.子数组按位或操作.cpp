/*
* @lc app=leetcode.cn id=898 lang=cpp
*
* [898] 子数组按位或操作
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution{
    public:
int subarrayBitwiseORs(vector<int>& A) {
	int maxval = *max_element(A.begin(), A.end());
	int mask = 1;
	while (maxval >= mask)
		mask <<= 1;
	mask -= 1;
	unordered_set<int> nums;
	for (int i = 0; i < A.size(); ++i) {
		int val = A[i];
		nums.insert(val);
		for (int j = i - 1; j >= 0 && val != mask; --j) {
			val |= A[j];
			nums.insert(val);
		}
	}
	return nums.size();
}
};
// @lc code=end

