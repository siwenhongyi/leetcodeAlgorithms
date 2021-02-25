/*
* @lc app=leetcode.cn id=667 lang=cpp
*
* [667] 优美的排列 II
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
public:
	vector<int> constructArray(int n, int k) {
		vector<int> resVec(n, 0);
		int numK = k + 1, numTemp = 1;
		//下标段[0, k]中，偶数下标填充[1,2,3..]
                for (int i = 0; i <= k; i += 2){
                        resVec[i] = numTemp++;
                }
               //下标段[0, k]中，奇数下标填充[k + 1, k, k - 1...]
               for (int i = 1; i <= k; i += 2){
                        resVec[i] = numK--;
               }
               //下标段[k + 1, n - 1]都是顺序填充
		for (int i = k + 1; i < n; ++i) {
			resVec[i] = i + 1;
		}
		return resVec;
	}
};
// @lc code=end

