/*
* @lc app=leetcode.cn id=845 lang=cpp
*
* [845] 数组中的最长山脉
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
public:
	int longestMountain(vector<int>& A) {
		int res = 0;
		int n = A.size();
		int i, j,k;
        bool x,y;
		i = 0;
		while(i<n){
			j = i + 1;
            x=y=false;
			while (j<n && A[j]>A[j - 1]){
                x=true;
				j++;
            }
            k=j;
			while (x&&j < n && A[j] < A[j - 1]){
                y=true;
				j++;
            }
            if(x+y==2)
                res = max(res, j - i);
			i = k;
		}
		return res;
	}
};

// @lc code=end

