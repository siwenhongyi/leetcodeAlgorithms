/*
* @lc app=leetcode.cn id=976 lang=cpp
*
* [976] 三角形的最大周长
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        int res = 0,n = A.size();
        sort(A.begin(),A.end());
        for(int i = n-1;i>=2;i--){
            if(A[i]<A[i-1]+A[i-2])
                return A[i]+A[i-1]+A[i-2];     
        }
        return 0;
    }
};
// @lc code=end

